from fpdf import FPDF

# Create PDF object
pdf = FPDF()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()
pdf.set_font("Arial", size=12)

# Add title
pdf.set_font("Arial", style="B", size=16)
pdf.cell(0, 10, "Comparison Between C and C++", ln=True, align="C")
pdf.ln(10)

# Add table headers
pdf.set_font("Arial", style="B", size=12)
pdf.cell(60, 10, "Aspect", border=1, align="C")
pdf.cell(65, 10, "C", border=1, align="C")
pdf.cell(65, 10, "C++", border=1, align="C")
pdf.ln()

# Table content
comparison = [
    ("Paradigm", "Procedural programming", "Multi-paradigm: Procedural, OOP, Generic"),
    ("Year Introduced", "1972", "1983"),
    ("Standard Versions", "C89, C99, C11, C17, C23", "C++98, C++03, C++11, C++14, C++17, C++20, C++23"),
    ("Inheritance", "Not supported", "Supported through classes"),
    ("Encapsulation", "Not supported", "Supported using classes and access specifiers"),
    ("Data Abstraction", "Limited (structs and function pointers)", "Supported with classes and interfaces"),
    ("Polymorphism", "Not supported", "Supported (Compile-time and Run-time)"),
    ("Operator Overloading", "Not available", "Supported"),
    ("Namespace Support", "Not available", "Available via namespace"),
    ("Memory Management", "Manual using malloc/calloc/free", "Manual and automatic with smart pointers"),
    ("Standard Library", "Limited (stdio, math, etc.)", "Extensive (STL: containers, algorithms, iterators)"),
    ("File Extension", ".c", ".cpp"),
    ("Exception Handling", "Error handling via errno or return codes", "Supported via try, catch, and throw"),
    ("Default Arguments", "Not supported", "Supported"),
    ("Inline Functions", "Not in older versions; macros used", "Fully supported"),
    ("Performance", "Slightly faster due to low-level constructs", "Slightly slower due to abstractions"),
    ("Pointers", "Fully supported", "Supported; can be avoided with references and STL"),
    ("Templates", "Not available", "Supported (function templates, class templates)"),
    ("Use Cases", "Embedded systems, OS, low-level programming", "Apps, games, GUIs, large-scale systems"),
    ("Learning Curve", "Simpler and easier for beginners", "Steeper due to OOP and templates"),
]

# Add content to PDF
pdf.set_font("Arial", size=10)
for row in comparison:
    pdf.cell(60, 10, row[0], border=1)
    pdf.cell(65, 10, row[1], border=1)
    pdf.cell(65, 10, row[2], border=1)
    pdf.ln()

# Save the PDF file
output_path = "D:\MyFiles\Programming\C-C++ (Repos and Projects)\C_vs_CPP_Comparison.pdf"
pdf.output(output_path)
output_path
