#!/bin/bash

# Parent directory where folders will be created
parent_dir="Semester_VI"

# Array of courses and their types (Theory or Practical)
courses=(
    "CE3632 Environmental_Studies MLC"
    "HS3606 Engineering_Economics HSMC"
    "CS3634 Mini_project_Stage_II SBC"
    "CS3635 Introduction_to_Artificial_Intelligence IOC"
    "CS3644 Computer_Graphics DEC"
    "CS3645 Computer_Graphics_Laboratory LC"
    "CS3636 Operating_Systems PCC"
    "CS3637 Operating_Systems_Laboratory LC"
    "CS3638 Design_and_Analysis_of_Algorithms PCC"
    "CS3639 Data_Science PCC"
    "CS3640 Data_Science_Laboratory LC"
)

# Create the parent directory
mkdir -p "$parent_dir"

# Loop through each course
for course in "${courses[@]}"; do
    # Split the course into course name and type
    course_details=($course)
    course_name="${course_details[1]}"
    course_code="${course_details[0]}"
    course_type="${course_details[2]}"

    # Create course directory
    course_dir="$parent_dir/$course_name"
    mkdir -p "$course_dir"

    # Check if the course has theory or practical
    if [[ "$course_type" == "MLC" || "$course_type" == "HSMC" || "$course_type" == "SBC" || "$course_type" == "IOC" || "$course_type" == "DEC" || "$course_type" == "PCC" ]]; then
        # Create subfolders for theory courses
        mkdir -p "$course_dir/Assignments" "$course_dir/Projects" "$course_dir/Notes"
    fi
    if [[ "$course_type" == "LC" || "$course_type" == "PCC" ]]; then
        # Create subfolders for practical courses
        mkdir -p "$course_dir/Practice" "$course_dir/LAB_Copy" "$course_dir/Notes"
    fi
done

echo "Folders created successfully!"

