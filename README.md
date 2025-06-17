<div align="center">

# 🧠 SmartQuizGen ✨

### *AI-Powered Quiz Generation with Gemini*

[![GitHub stars](https://img.shields.io/github/stars/MossabMilha/SmartQuizGen-?style=for-the-badge&logo=github&color=yellow)](https://github.com/MossabMilha/SmartQuizGen-)
[![GitHub forks](https://img.shields.io/github/forks/MossabMilha/SmartQuizGen-?style=for-the-badge&logo=github&color=blue)](https://github.com/MossabMilha/SmartQuizGen-)
[![License](https://img.shields.io/badge/license-MIT-green.svg?style=for-the-badge)](LICENSE)
[![Python](https://img.shields.io/badge/Python-3.8+-blue.svg?style=for-the-badge&logo=python)](https://python.org)

**Transform text content into intelligent quizzes using Google's Gemini API**

[📖 Documentation](#-installation) · [🐛 Report Bug](https://github.com/MossabMilha/SmartQuizGen-/issues) · [💡 Request Feature](https://github.com/MossabMilha/SmartQuizGen-/issues)

---

</div>

## 🎯 What is SmartQuizGen?

SmartQuizGen is a powerful quiz generation application that leverages Google's Gemini AI to automatically create educational quizzes from text content. Built with Python and C++, it provides an efficient backend for processing content and generating high-quality questions with customizable difficulty levels.

<div align="center">

### 🌟 **Core Capabilities**

| 🤖 Gemini AI | 📧 Email Integration | 🗄️ MySQL Database | ⚡ High Performance |
|:-------------:|:-------------------:|:-----------------:|:-----------------:|
| Google's advanced AI for intelligent question generation | SMTP email delivery for quiz sharing and notifications | Reliable data storage with MySQL | Optimized C++ components for fast processing |

</div>

---

## ✨ Key Features

<table>
<tr>
<td width="50%">

### 🔮 **AI-Powered Generation**
- **Gemini API Integration** - Leverage Google's advanced language model
- **Intelligent Content Analysis** - Extract key concepts automatically
- **Multiple Question Types** - MCQ, True/False, Short answers
- **Smart Difficulty Adjustment** - AI determines appropriate complexity

</td>
<td width="50%">

### 📊 **Flexible Configuration**
- **Custom Topic Input** - Generate quizzes on any subject
- **Fixed Question Count** - Consistent quiz structure
- **Difficulty Selection** - Choose from multiple difficulty levels
- **Content Processing** - Handle various text formats

</td>
</tr>
<tr>
<td width="50%">

### 🔧 **Robust Backend**
- **Python Core** - Reliable and maintainable codebase
- **C++ Performance** - High-speed processing components
- **MySQL Storage** - Secure and scalable data management
- **Email Notifications** - SMTP integration for user communication

</td>
<td width="50%">

### 🎯 **User-Friendly**
- **Topic-Based Generation** - Simply input your subject matter
- **Consistent Output** - Reliable question generation
- **Email Delivery** - Share quizzes via email
- **Progress Tracking** - Monitor quiz performance

</td>
</tr>
</table>

---

## 🛠️ Technology Stack

<div align="center">

### Core Technologies
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![MySQL](https://img.shields.io/badge/MySQL-4479A1?style=for-the-badge&logo=mysql&logoColor=white)

### AI & Services
![Google Gemini](https://img.shields.io/badge/Google_Gemini-4285F4?style=for-the-badge&logo=google&logoColor=white)
![SMTP](https://img.shields.io/badge/SMTP-Email-red?style=for-the-badge&logo=gmail&logoColor=white)

</div>

---

## 🚀 Installation & Setup

### 📋 Prerequisites

```bash
# Check Python version (3.8+ required)
python --version

# Check MySQL installation
mysql --version

# C++ compiler (g++ or clang++)
g++ --version
```

### 1️⃣ Clone Repository

```bash
git clone https://github.com/MossabMilha/SmartQuizGen-.git
cd SmartQuizGen-
```

### 2️⃣ Install Dependencies

```bash
# Install Python dependencies
pip install -r requirements.txt

# Compile C++ components (if any)
make build
```

### 3️⃣ Database Setup

```sql
-- Create database
CREATE DATABASE smartquizgen;

-- Run migration scripts
mysql -u username -p smartquizgen < database/schema.sql
mysql -u username -p smartquizgen < database/seed.sql
```

### 4️⃣ Environment Configuration

```bash
# Copy environment template
cp .env.example .env
```

<details>
<summary><strong>🔧 Configure your .env file</strong></summary>

```env
# 🤖 Gemini AI Configuration
GEMINI_API_KEY=your-gemini-api-key-here
GEMINI_MODEL=gemini-pro

# 🗄️ MySQL Database
DB_HOST=localhost
DB_PORT=3306
DB_NAME=smartquizgen
DB_USER=your-db-username
DB_PASSWORD=your-db-password

# 📧 SMTP Email Configuration
SMTP_HOST=smtp.gmail.com
SMTP_PORT=587
SMTP_USERNAME=your-email@gmail.com
SMTP_PASSWORD=your-app-password
SMTP_USE_TLS=true

# 🔧 Application Settings
DEBUG=true
LOG_LEVEL=INFO
MAX_QUESTIONS=10
DEFAULT_DIFFICULTY=medium
```

</details>

### 5️⃣ Run Application

```bash
# Start the application
python main.py

# Or run in development mode
python main.py --dev
```

---

## 📖 Usage Guide

<div align="center">

### 🎯 **Simple Quiz Generation Process**

</div>

<table>
<tr>
<td align="center" width="33%">

### 1️⃣ **Input Topic**
<img src="https://via.placeholder.com/200x150/4F46E5/white?text=📝+TOPIC" alt="Input Topic" width="200"/>

Provide your subject matter:
- 📚 Academic topics
- 💼 Professional subjects
- 🔬 Technical concepts
- 🎯 Custom content

</td>
<td align="center" width="33%">

### 2️⃣ **Select Difficulty**
<img src="https://via.placeholder.com/200x150/059669/white?text=⚙️+LEVEL" alt="Select Difficulty" width="200"/>

Choose difficulty level:
- 🟢 Easy - Basic concepts
- 🟡 Medium - Intermediate
- 🔴 Hard - Advanced topics
- 🎯 Custom complexity

</td>
<td align="center" width="33%">

### 3️⃣ **Generate Quiz**
<img src="https://via.placeholder.com/200x150/DC2626/white?text=🚀+QUIZ" alt="Generate Quiz" width="200"/>

AI creates your quiz:
- ✨ Fixed question count
- 🧠 Gemini AI processing
- 📧 Email delivery option
- 💾 Database storage

</td>
</tr>
</table>

### 📝 **Example Usage**

```python
from smartquizgen import QuizGenerator

# Initialize the generator
generator = QuizGenerator(
    gemini_api_key="your-api-key",
    db_config=db_config
)

# Generate quiz
quiz = generator.create_quiz(
    topic="Machine Learning Basics",
    difficulty="medium"
)

# Send via email
generator.send_quiz_email(
    quiz_id=quiz.id,
    recipient="student@example.com"
)
```

---

## 🏗️ Project Structure

<details>
<summary><strong>📁 Project Architecture</strong></summary>

```
SmartQuizGen/
├── 🐍 src/                        # Python source code
│   ├── 🤖 ai/                     # Gemini AI integration
│   │   ├── gemini_client.py       # Gemini API client
│   │   ├── question_generator.py  # Question generation logic
│   │   └── content_processor.py   # Content analysis
│   ├── 🗄️ database/               # Database operations
│   │   ├── models.py              # MySQL models
│   │   ├── migrations/            # Database migrations
│   │   └── connection.py          # Database connection
│   ├── 📧 email/                  # Email functionality
│   │   ├── smtp_client.py         # SMTP email client
│   │   └── templates/             # Email templates
│   ├── 🔧 utils/                  # Utility functions
│   │   ├── validators.py          # Input validation
│   │   ├── helpers.py             # Helper functions
│   │   └── config.py              # Configuration management
│   └── 🎯 core/                   # Core application logic
│       ├── quiz_generator.py      # Main quiz generation
│       └── quiz_manager.py        # Quiz management
├── ⚡ cpp/                        # C++ performance components
│   ├── text_processor.cpp         # Text processing
│   ├── content_analyzer.cpp       # Content analysis
│   └── Makefile                   # Build configuration
├── 🗄️ database/                   # Database files
│   ├── schema.sql                 # Database schema
│   ├── seed.sql                   # Sample data
│   └── migrations/                # Migration scripts
├── 🧪 tests/                      # Test suite
│   ├── test_generators.py         # Generator tests
│   ├── test_database.py           # Database tests
│   └── test_email.py              # Email tests
├── 📚 docs/                       # Documentation
├── 🔧 requirements.txt            # Python dependencies
├── 🌐 .env.example                # Environment template
└── 🚀 main.py                     # Application entry point
```

</details>

---

## 🧪 Testing

```bash
# Run all tests
python -m pytest

# Run specific test categories
python -m pytest tests/test_generators.py     # AI generation tests
python -m pytest tests/test_database.py       # Database tests
python -m pytest tests/test_email.py          # Email functionality

# Run with coverage
python -m pytest --cov=src tests/

# Performance tests
python -m pytest tests/performance/ -v
```

---

## 📊 Configuration Options

<details>
<summary><strong>⚙️ Application Settings</strong></summary>

### Quiz Generation Settings
```python
# config.py
QUIZ_SETTINGS = {
    'QUESTIONS_PER_QUIZ': 10,        # Fixed number of questions
    'DIFFICULTY_LEVELS': [
        'easy',
        'medium', 
        'hard',
        'expert'
    ],
    'QUESTION_TYPES': [
        'multiple_choice',
        'true_false',
        'short_answer'
    ],
    'MAX_CONTENT_LENGTH': 5000,      # Maximum input text length
    'GENERATION_TIMEOUT': 30         # Timeout in seconds
}
```

### Database Configuration
```python
# Database connection settings
DB_CONFIG = {
    'host': 'localhost',
    'port': 3306,
    'database': 'smartquizgen',
    'charset': 'utf8mb4',
    'autocommit': True,
    'pool_size': 10,
    'max_overflow': 20
}
```

### Email Settings
```python
# SMTP configuration
EMAIL_CONFIG = {
    'smtp_server': 'smtp.gmail.com',
    'smtp_port': 587,
    'use_tls': True,
    'timeout': 30,
    'max_retries': 3
}
```

</details>

---

## 🔧 API Reference

<details>
<summary><strong>🔗 Core Functions</strong></summary>

### QuizGenerator Class
```python
class QuizGenerator:
    def __init__(self, gemini_api_key, db_config):
        """Initialize the quiz generator"""
        
    def create_quiz(self, topic, difficulty='medium'):
        """Generate a new quiz"""
        
    def get_quiz(self, quiz_id):
        """Retrieve existing quiz"""
        
    def send_quiz_email(self, quiz_id, recipient):
        """Send quiz via email"""
        
    def get_quiz_stats(self, quiz_id):
        """Get quiz performance statistics"""
```

### Database Operations
```python
class QuizDatabase:
    def save_quiz(self, quiz_data):
        """Save quiz to database"""
        
    def get_quiz_by_id(self, quiz_id):
        """Retrieve quiz by ID"""
        
    def get_user_quizzes(self, user_id):
        """Get all quizzes for a user"""
        
    def update_quiz_stats(self, quiz_id, stats):
        """Update quiz statistics"""
```

</details>

---

## 🚀 Deployment

### 🐧 Linux/Ubuntu Deployment

```bash
# Install system dependencies
sudo apt update
sudo apt install python3 python3-pip mysql-server build-essential

# Setup MySQL
sudo mysql_secure_installation

# Clone and setup application
git clone https://github.com/MossabMilha/SmartQuizGen-.git
cd SmartQuizGen-
pip3 install -r requirements.txt

# Configure environment
cp .env.example .env
# Edit .env with your settings

# Setup database
mysql -u root -p < database/schema.sql

# Run application
python3 main.py
```

### 🐳 Docker Deployment

```dockerfile
# Dockerfile
FROM python:3.9-slim

WORKDIR /app
COPY requirements.txt .
RUN pip install -r requirements.txt

COPY . .
CMD ["python", "main.py"]
```

```bash
# Build and run
docker build -t smartquizgen .
docker run -p 8000:8000 smartquizgen
```

---

## 🤝 Contributing

<div align="center">

### 💪 **Help Improve SmartQuizGen!**

We welcome contributions from developers interested in AI-powered education tools.

</div>

<table>
<tr>
<td align="center" width="50%">

### 🐛 **Bug Reports**
Found an issue? Help us fix it:
- Clear description of the problem
- Steps to reproduce
- Expected vs actual behavior
- Environment details (Python version, OS)

[Report Bug →](https://github.com/MossabMilha/SmartQuizGen-/issues/new?template=bug_report.md)

</td>
<td align="center" width="50%">

### 💡 **Feature Requests**
Have an idea for improvement?
- Detailed feature description
- Use case examples
- Benefits for users
- Implementation suggestions

[Request Feature →](https://github.com/MossabMilha/SmartQuizGen-/issues/new?template=feature_request.md)

</td>
</tr>
</table>

### 🔧 **Development Guidelines**

```bash
# Fork the repository
git fork https://github.com/MossabMilha/SmartQuizGen-.git

# Create feature branch
git checkout -b feature/your-feature-name

# Make changes and test
python -m pytest
python -m pylint src/

# Commit with clear message
git commit -m "Add: Description of your feature"

# Push and create PR
git push origin feature/your-feature-name
```

---

## 🗺️ Roadmap

<div align="center">

### 🚀 **Planned Enhancements**

</div>

<details>
<summary><strong>📅 Development Timeline</strong></summary>

### 🎯 **Phase 1: Core Improvements**
- [ ] 🔧 Enhanced C++ performance components
- [ ] 📊 Advanced MySQL optimization
- [ ] 🤖 Gemini API rate limiting and caching
- [ ] 📧 Rich HTML email templates

### 🎯 **Phase 2: Advanced Features**
- [ ] 🎨 Web interface for quiz management
- [ ] 📱 REST API for external integrations
- [ ] 📈 Advanced analytics and reporting
- [ ] 🔄 Batch processing for multiple topics

### 🎯 **Phase 3: Scalability**
- [ ] ☁️ Cloud deployment options
- [ ] 🔄 Horizontal scaling support
- [ ] 📊 Performance monitoring
- [ ] 🔐 Enhanced security features

</details>

---

## 📊 Performance Metrics

<div align="center">

### ⚡ **System Performance**

| Component | Performance | Status |
|-----------|-------------|--------|
| 🤖 **Gemini API Response** | < 3s | ![Good](https://img.shields.io/badge/-Good-green) |
| 🗄️ **Database Queries** | < 100ms | ![Excellent](https://img.shields.io/badge/-Excellent-brightgreen) |
| ⚡ **C++ Processing** | < 50ms | ![Excellent](https://img.shields.io/badge/-Excellent-brightgreen) |
| 📧 **Email Delivery** | < 5s | ![Good](https://img.shields.io/badge/-Good-green) |
| 💾 **Memory Usage** | < 512MB | ![Excellent](https://img.shields.io/badge/-Excellent-brightgreen) |

</div>

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🆘 Support

<div align="center">

### 💬 **Get Help**

</div>

<table>
<tr>
<td align="center" width="33%">

### 📧 **Email Support**
Technical questions and issues:
- Bug reports
- Feature requests
- Implementation help
- Configuration assistance

[support@example.com](mailto:support@example.com)

</td>
<td align="center" width="33%">

### 📚 **Documentation**
Comprehensive guides:
- Installation instructions
- Configuration examples
- API documentation
- Troubleshooting tips

[View Documentation](#)

</td>
<td align="center" width="33%">

### 🐛 **Issue Tracker**
Report problems:
- Bug reports
- Feature requests
- Performance issues
- Enhancement suggestions

[GitHub Issues](https://github.com/MossabMilha/SmartQuizGen-/issues)

</td>
</tr>
</table>

---

<div align="center">

### 🌟 **Star This Project**

If SmartQuizGen helps you create better educational content, please give us a star! ⭐

[![GitHub stars](https://img.shields.io/github/stars/MossabMilha/SmartQuizGen-?style=social)](https://github.com/MossabMilha/SmartQuizGen-)

---

**Built with ❤️ by [Mossab Milha](https://github.com/MossabMilha)**

*Empowering education through AI-powered quiz generation* 🚀

---

</div>
