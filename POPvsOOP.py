from PIL import Image, ImageDraw, ImageFont

# Create a blank image with white background
width, height = 800, 400
image = Image.new("RGB", (width, height), "white")
draw = ImageDraw.Draw(image)

# Define fonts (fallback if custom fonts are unavailable)
font_title = ImageFont.load_default()
font_text = ImageFont.load_default()

# Draw headers
draw.rectangle([0, 0, width // 2, 50], fill="orange")
draw.rectangle([width // 2, 0, width, 50], fill="orange")
draw.text((width // 4 - 60, 15), "Procedural", fill="white", font=font_title)
draw.text((3 * width // 4 - 80, 15), "Object-Oriented", fill="white", font=font_title)

# Draw Procedural section
draw.rectangle([50, 100, width // 2 - 50, 300], outline="black", width=2)
draw.text((90, 110), "Step 1", fill="black", font=font_text)
draw.line([120, 140, 120, 180], fill="black", width=2)
draw.text((90, 190), "Step 2", fill="black", font=font_text)
draw.line([120, 220, 120, 260], fill="black", width=2)
draw.text((90, 270), "Step 3", fill="black", font=font_text)

# Draw Object-Oriented section
draw.rectangle([width // 2 + 50, 100, width - 50, 300], outline="black", width=2)
draw.text((width // 2 + 90, 110), "Animal", fill="black", font=font_text)
draw.line([width // 2 + 120, 140, width // 2 + 120, 180], fill="black", width=2)
draw.text((width // 2 + 60, 190), "Dog", fill="black", font=font_text)
draw.text((width // 2 + 150, 190), "Cat", fill="black", font=font_text)
draw.line([width // 2 + 120, 220, width // 2 + 60, 260], fill="black", width=2)
draw.line([width // 2 + 120, 220, width // 2 + 150, 260], fill="black", width=2)

# Save the image
file_path = "D:\MyFiles\Programming\C-C++ (Repos and Projects)\procedural_vs_oop_diagram.png"
image.save(file_path)
file_path
