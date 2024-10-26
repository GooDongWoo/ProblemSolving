import math
import random

def is_inside_circle(x, y, circle):
    """Check if a point (x, y) is inside a given circle."""
    cx, cy, r = circle
    return (x - cx) ** 2 + (y - cy) ** 2 <= r ** 2

def estimate_area(circles, num_samples=100000):
    # Determine the bounding box
    min_x = min(cx - r for cx, cy, r in circles)
    max_x = max(cx + r for cx, cy, r in circles)
    min_y = min(cy - r for cx, cy, r in circles)
    max_y = max(cy + r for cx, cy, r in circles)
    
    # Calculate the area of the bounding box
    bounding_box_area = (max_x - min_x) * (max_y - min_y)
    
    # Monte Carlo simulation
    inside_count = 0
    for _ in range(num_samples):
        x = random.uniform(min_x, max_x)
        y = random.uniform(min_y, max_y)
        if any(is_inside_circle(x, y, circle) for circle in circles):
            inside_count += 1
    
    # Estimate the total area covered by circles
    estimated_area = (inside_count / num_samples) * bounding_box_area
    return estimated_area

# Input reading
n = int(input().strip())
circles = []
for _ in range(n):
    x, y, r = map(int, input().strip().split())
    circles.append((x, y, r))

# Estimate the damaged area
damaged_area = estimate_area(circles)
print(f"{damaged_area:.6f}")
