# Simple Genetic Algorithm for Function Optimization

[English](#english) | [فارسی](#فارسی)

## English

### Overview
This project implements a simple genetic algorithm for function optimization in C++. It demonstrates basic concepts of genetic algorithms, which are a fundamental technique in artificial intelligence and machine learning.

### Features
- Population-based optimization
- Tournament selection
- Single-point crossover
- Mutation for genetic diversity
- Elitism to preserve the best solution

### How to Use
1. Clone the repository
2. Compile the C++ file:
   ```
   g++ genetic_algorithm.cpp -o genetic_algorithm
   ```
3. Run the executable:
   ```
   ./genetic_algorithm
   ```

### Customization
You can customize the algorithm by modifying the following parameters in the `main()` function:
- Population size
- Chromosome length
- Mutation rate
- Number of generations

To optimize a different function, modify the `fitness_function()` in the code.

### Requirements
- C++11 or later
- Standard C++ libraries



---

## فارسی

### نمای کلی
این پروژه یک الگوریتم ژنتیک ساده برای بهینه‌سازی تابع در ++C پیاده‌سازی می‌کند. این پروژه مفاهیم اساسی الگوریتم‌های ژنتیک را نشان می‌دهد که یک تکنیک بنیادی در هوش مصنوعی و یادگیری ماشین هستند.

### ویژگی‌ها
- بهینه‌سازی مبتنی بر جمعیت
- انتخاب به روش تورنمنت
- تقاطع تک‌نقطه‌ای
- جهش برای حفظ تنوع ژنتیکی
- نخبه‌گرایی برای حفظ بهترین راه حل

### نحوه استفاده
1. مخزن را کلون کنید
2. فایل ++C را کامپایل کنید:
   ```
   g++ genetic_algorithm.cpp -o genetic_algorithm
   ```
3. فایل اجرایی را اجرا کنید:
   ```
   ./genetic_algorithm
   ```

### سفارشی‌سازی
شما می‌توانید الگوریتم را با تغییر پارامترهای زیر در تابع `()main` سفارشی کنید:
- اندازه جمعیت
- طول کروموزوم
- نرخ جهش
- تعداد نسل‌ها

برای بهینه‌سازی تابع متفاوت، `()fitness_function` را در کد تغییر دهید.

### نیازمندی‌ها
- ++C11 یا بالاتر
- کتابخانه‌های استاندارد ++C


