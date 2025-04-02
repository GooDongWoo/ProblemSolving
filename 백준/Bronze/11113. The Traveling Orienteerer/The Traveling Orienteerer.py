import math

def calculate_distance(point1, point2):
    """
    Calculate the Euclidean distance between two points.
    
    Args:
        point1 (tuple): (x, y) coordinates of the first point
        point2 (tuple): (x, y) coordinates of the second point
        
    Returns:
        float: The distance between the two points
    """
    x1, y1 = point1
    x2, y2 = point2
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def calculate_route_distance(control_points, route_indices):
    """
    Calculate the total distance of a route through specified control points.
    
    Args:
        control_points (list): List of (x, y) coordinates of all control points
        route_indices (list): List of indices defining the route order
        
    Returns:
        float: The total distance of the route
    """
    total_distance = 0.0
    
    # Calculate distance between consecutive points in the route
    for i in range(len(route_indices) - 1):
        current_point = control_points[route_indices[i]]
        next_point = control_points[route_indices[i + 1]]
        total_distance += calculate_distance(current_point, next_point)
    
    return total_distance

def main():
    # Read the number of control points
    n = int(input())
    
    # Read coordinates of all control points
    control_points = []
    for _ in range(n):
        x, y = map(float, input().split())
        control_points.append((x, y))
    
    # Read the number of routes
    m = int(input())
    
    # Process each route
    for _ in range(m):
        # Read the number of control points in this route
        p = int(input())
        
        # Read the indices of control points for this route
        route_indices = list(map(int, input().split()))
        
        # Calculate and print the total route distance (rounded to nearest integer)
        distance = calculate_route_distance(control_points, route_indices)
        print(round(distance))

if __name__ == "__main__":
    main()