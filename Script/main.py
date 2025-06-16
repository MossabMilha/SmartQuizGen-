import sys
import os
import sqlite3
import google.generativeai as genai
import re
import json
import tempfile

genai.configure(api_key="AIzaSyCQQKLp1V2GEgnHEab1fKKL6K6O5lcBXZY")
script_dir = os.path.dirname(os.path.abspath(__file__))

db_path = os.path.join(script_dir, "..", "DB", "SmartQuizGen.db")

def GetPdf(id):
    try:
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        cursor.execute("SELECT filename, data, user_id FROM pdfs WHERE id = ?", (id,))
        row = cursor.fetchone()
        conn.close()

        if row is None:
            return  # No return if the PDF isn't found

        filename, pdf_data, user_id = row
        temp_dir = tempfile.gettempdir()
        temp_path = os.path.join(temp_dir, filename)

        with open(temp_path, "wb") as file:
            file.write(pdf_data)

        return {"user_id": user_id, "pdf_id": id, "path": temp_path}

    except sqlite3.Error as e:
        return  # No return on error

def generate(file_path, user_id, pdf_id):
    try:
        uploaded_file = genai.upload_file(path=file_path)
        model = genai.GenerativeModel("gemini-1.5-flash")

        prompt = """
        I will upload a PDF. Your task is to generate 5 multiple-choice quiz questions from it.
        Format the output as JSON with this structure with no extra thing even a comma is not allow to be add:
        {
          "quiz": [
            {
              "question": "Sample question?",
              "options": ["A", "B", "C", "D"],
              "correct_answer": "B"
            }
          ],
          "error": null
        }
        """

        response = model.generate_content(
            contents=[{"file_data": {"file_uri": uploaded_file.uri}}, {"text": prompt}],
            generation_config={"temperature": 0.7, "max_output_tokens": 1024}
        )

        match = re.search(r'(\{.*\})', response.text, re.DOTALL)
        if match:
            quiz_json = match.group(1)
        else:
            quiz_json = '{"quiz": [], "error": "Error in generating quiz."}'

        print(quiz_json)
        save_quiz_to_db(user_id, pdf_id, quiz_json)
        return quiz_json

    except Exception as e:
        error_result = f'{{"quiz": [], "error": "Error in generating quiz: {str(e)}"}}'
        print(error_result)
        return error_result

def save_quiz_to_db(user_id, pdf_id, quiz_data):
    try:
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()

        cursor.execute("INSERT INTO quizzes (user_id, pdf_id, data) VALUES (?, ?, ?)", (user_id, pdf_id, quiz_data))

        conn.commit()
        conn.close()

    except sqlite3.Error as e:
        pass

if __name__ == "__main__":
    if len(sys.argv) > 1:
        pdf_id = int(sys.argv[1])
        pdf_path = GetPdf(pdf_id)

        if pdf_path:  # Only proceed if pdf_path was returned (not None)
            result = generate(pdf_path["path"], pdf_path["user_id"], pdf_path["pdf_id"])
        else:
            print("PDF not found")
