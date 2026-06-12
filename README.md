# 🍽️ TasteBite

**Smart Restaurant Management & Food Ordering System**

HTML • CSS • JavaScript • PHP • MySQL

Revolutionizing Restaurant Operations with Intelligent Order Management and Table Booking 🍕

## 🌟 Overview

TasteBite is a comprehensive restaurant management system designed to streamline daily operations through efficient order management, table booking, food catalog management, and billing. Built as a full-stack web application, this platform helps restaurants optimize their workflow and enhance customer experience.

## 🎯 Key Features

- 🍕 **Food Catalog Management** - Add, update, and manage menu items with pricing
- 📋 **Order Management** - Create, track, and complete customer orders
- 🪑 **Table Booking System** - Reserve and manage restaurant seating arrangements
- 💰 **Smart Billing** - Generate detailed bills with automatic calculations
- 👥 **Customer Management** - Track and manage customer information
- 🔐 **Secure Authentication** - User login and registration system
- 📊 **Order History** - View and retrieve past orders
- 🧾 **PDF Bill Generation** - Generate professional bills using FPDF
- 📱 **User-Friendly Interface** - Intuitive design for easy navigation

## 🏗️ System Architecture

```
TasteBite Architecture
├── 🎨 Frontend (HTML/CSS/JavaScript)
│   ├── 🏠 Login & Registration System
│   ├── 📋 Order Management Dashboard
│   ├── 🍽️ Food Menu Management
│   ├── 🪑 Table Booking Interface
│   ├── 💰 Billing System
│   └── 👥 Customer Management
│
├── 🔧 Backend (PHP)
│   ├── 🔐 Authentication (login.php, SignUp.php)
│   ├── 🍕 Food Operations (addfood.php, updfood.php, cnclfood.php)
│   ├── 📋 Order Operations (addorder.php, getorders.php, deleteorder.php)
│   ├── 🪑 Table Management (booktable.php, cnclseat.php, cnfseat.php)
│   ├── 💰 Billing (Bill.php, completebill.php)
│   ├── 👥 Customer Data (getCust.php)
│   └── 🔍 Utility Functions (getprice.php)
│
└── 💾 Database (MySQL)
    ├── 👤 Users Table
    ├── 🍽️ Food Catalog
    ├── 📋 Orders Table
    ├── 🪑 Table Reservations
    ├── 💰 Bills & Transactions
    └── 👥 Customer Information
```

## 🚀 Quick Start

### Prerequisites

- 🌐 **Web Server** - Apache with PHP support
- 🐘 **PHP** - Version 7.0 or higher
- 💾 **MySQL** - Database server
- 📦 **FPDF Library** - For PDF bill generation

### Installation

```bash
# 1. Clone the repository
git clone https://github.com/your-repo/TasteBite.git

# 2. Navigate to project directory
cd TasteBite

# 3. Create a MySQL database
mysql -u root -p < database_schema.sql

# 4. Configure database connection in PHP files
# Update database credentials in your PHP connection files

# 5. Place files in web server directory
cp -r TasteBite/ /var/www/html/

# 6. Start Apache and MySQL
sudo service apache2 start
sudo service mysql start
```

### 🌐 Access the Application

- **Local Development:** `http://localhost/TasteBite/`
- **Login Page:** `http://localhost/TasteBite/index.html`
- **Default Credentials:** Create new account via Sign Up page

## 📱 Application Pages & Features

### 🏠 Login & Registration
- User authentication system
- Secure password handling
- New account registration
- Session management

### 🍕 Food Management
- **Add Food Items** - Add new menu items with prices and descriptions
- **Update Food** - Modify existing menu items
- **Cancel Food** - Remove items from inventory
- **Food Catalog** - Browse complete menu

### 📋 Order Management
- **Create Orders** - Place new customer orders
- **View Orders** - Retrieve and track orders
- **Manage Orders** - Update order status
- **Delete Orders** - Cancel unwanted orders
- **Order History** - Access complete order records

### 🪑 Table Booking
- **Book Table** - Reserve seating arrangements
- **Confirm Seat** - Confirm table reservations
- **Cancel Seat** - Release reserved tables
- **Seat Availability** - Check real-time table status

### 💰 Billing System
- **Generate Bills** - Create itemized bills
- **Bill Calculation** - Automatic price calculations
- **PDF Export** - Download bills as PDF
- **Complete Billing** - Mark orders as paid

### 👥 Customer Management
- **Customer Profiles** - Store customer information
- **Contact Details** - Manage phone numbers and addresses
- **Order Tracking** - Link customers to their orders
- **Customer History** - View customer records

## 🛠️ Technology Stack

| Category | Technology | Purpose |
|----------|-----------|---------|
| 🎨 Frontend | HTML5 | Page Structure |
| 🎨 Styling | CSS3 | User Interface Design |
| ✨ Interactivity | JavaScript (Vanilla) | Dynamic Behavior |
| 🔧 Backend | PHP 7.0+ | Server-Side Logic |
| 💾 Database | MySQL | Data Storage |
| 📄 PDF Generation | FPDF Library | Bill Documentation |
| 🌐 Server | Apache | Web Server |

## 📁 Project Structure

```
TasteBite/
├── index.html                    # Login/Registration page
├── login.php                     # Authentication handler
├── SignUp.php                    # User registration
├── addfood.php                   # Add food items
├── updfood.php                   # Update food items
├── cnclfood.php                  # Cancel/delete food items
├── addorder.php                  # Create orders
├── getorders.php                 # Retrieve orders
├── deleteorder.php               # Delete orders
├── booktable.php                 # Table booking
├── cnclseat.php                  # Cancel seat reservation
├── cnfseat.php                   # Confirm seat reservation
├── Bill.php                      # Generate bills
├── completebill.php              # Complete billing
├── getCust.php                   # Retrieve customer data
├── getprice.php                  # Get food pricing
├── fpdf/                         # FPDF library directory
│   └── fpdf.php                  # PDF generation class
├── P/                            # Additional resources
├── pic1.png - pic7.png           # UI Images
└── README.md                     # This file
```

## 🚀 Development Commands

```bash
# Start Apache web server
sudo service apache2 start

# Start MySQL database
sudo service mysql start

# View Apache logs
tail -f /var/log/apache2/error.log

# Access MySQL
mysql -u root -p

# Check PHP installation
php -v
```

## 💻 File Descriptions

### Core Files

- **index.html** - Main login and registration interface with responsive design
- **login.php** - Handles user authentication and session management
- **SignUp.php** - Processes new user registration

### Food Management

- **addfood.php** - Add new food items to the menu
- **updfood.php** - Modify existing food items and prices
- **cnclfood.php** - Remove food items from inventory

### Order Management

- **addorder.php** - Create new customer orders
- **getorders.php** - Retrieve order details and history
- **deleteorder.php** - Cancel orders

### Table Management

- **booktable.php** - Reserve tables
- **cnfseat.php** - Confirm table reservations
- **cnclseat.php** - Cancel table reservations

### Billing

- **Bill.php** - Generate itemized bills
- **completebill.php** - Mark bills as paid and complete

### Utilities

- **getCust.php** - Fetch customer information
- **getprice.php** - Retrieve food pricing information

## 🔐 Security Features

- User authentication with password validation
- Session-based access control
- Input validation and sanitization
- Secure database connections
- Role-based access management

## 📊 Database Schema

### Users Table
```
- user_id (Primary Key)
- username (Unique)
- password (Hashed)
- email
- created_at
```

### Food Items Table
```
- food_id (Primary Key)
- food_name
- price
- description
- status
```

### Orders Table
```
- order_id (Primary Key)
- user_id (Foreign Key)
- food_id (Foreign Key)
- quantity
- total_price
- order_date
- status
```

### Table Reservations Table
```
- reservation_id (Primary Key)
- user_id (Foreign Key)
- table_number
- seats
- reservation_date
- status
```

### Bills Table
```
- bill_id (Primary Key)
- order_id (Foreign Key)
- amount
- payment_status
- bill_date
```

## 🤝 Contributing

We welcome contributions! Please follow these steps:

1. 🍴 Fork the repository
2. 🌿 Create a feature branch (`git checkout -b feature/amazing-feature`)
3. 💾 Commit your changes (`git commit -m 'Add amazing feature'`)
4. 📤 Push to the branch (`git push origin feature/amazing-feature`)
5. 🔄 Open a Pull Request

### Contribution Guidelines

- Follow the existing code style
- Add comments for complex logic
- Test changes thoroughly before submitting
- Update documentation as needed

## 📝 Usage Examples

### Adding a New Food Item

```php
POST to: addfood.php
Parameters:
- food_name: "Margherita Pizza"
- price: 250
- description: "Fresh tomato and mozzarella"
```

### Creating an Order

```php
POST to: addorder.php
Parameters:
- food_id: 1
- quantity: 2
- user_id: 5
```

### Booking a Table

```php
POST to: booktable.php
Parameters:
- table_number: 5
- seats: 4
- reservation_date: "2024-12-20"
```

## 🐛 Troubleshooting

### Database Connection Issues
- Verify MySQL is running
- Check database credentials in PHP files
- Ensure database and tables exist

### File Upload Issues
- Check file permissions
- Verify upload directory exists
- Review PHP upload configuration

### FPDF Not Working
- Ensure fpdf/ directory exists
- Check FPDF library files are present
- Verify file paths in Bill.php

## 📄 License

This project is open source and available under the MIT License.

## 👥 Team

- **Project Lead** - Restaurant Management Team
- **Developers** - Full Stack Development Team
- **Designer** - UI/UX Design Team

## 🌟 Future Enhancements

- 📱 Mobile application
- 🤖 AI-powered recommendations
- 💳 Online payment integration
- 📊 Advanced analytics dashboard
- 🔔 Real-time notifications
- 🗺️ Location-based services
- ⭐ Customer ratings and reviews


## 🎉 Acknowledgments

- Built with ❤️ for efficient restaurant management
- Inspired by real-world restaurant challenges
- Dedicated to improving dining experiences

---

**🍽️ TasteBite - Making Restaurant Management Delicious!**

Made with 🍕 for Restaurant Management Excellence

© 2026 TasteBite. All rights reserved.
