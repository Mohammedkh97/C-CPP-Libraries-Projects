import matplotlib.pyplot as plt

# Data for the comparison
categories = [
    "Focus", "Data Management", "Code Reusability", 
    "Scalability", "Approach", "Real-World Modeling"
]

pop_values = [7, 5, 3, 4, 7, 2]  # Procedural values
oop_values = [5, 9, 8, 9, 5, 10]  # OOP values

# Create a radar chart
fig, ax = plt.subplots(figsize=(8, 8), subplot_kw=dict(polar=True))

# Create the angles for the radar chart
angles = [n / float(len(categories)) * 2 * 3.14159 for n in range(len(categories))]
angles += angles[:1]

# Extend the values to match the circle
pop_values += pop_values[:1]
oop_values += oop_values[:1]

# Plot data
ax.plot(angles, pop_values, label="Procedural Programming", linestyle='-', linewidth=2, marker='o')
ax.fill(angles, pop_values, alpha=0.25)

ax.plot(angles, oop_values, label="Object-Oriented Programming", linestyle='--', linewidth=2, marker='x')
ax.fill(angles, oop_values, alpha=0.25)

# Add category labels to the chart
ax.set_yticks([2, 4, 6, 8, 10])
ax.set_yticklabels(['2', '4', '6', '8', '10'], color="grey", fontsize=10)
ax.set_xticks(angles[:-1])
ax.set_xticklabels(categories, fontsize=12, ha="center")

# Title and legend
plt.title("Procedural vs Object-Oriented Programming", size=15, y=1.1)
ax.legend(loc='upper right', bbox_to_anchor=(1.2, 1))

plt.show()
