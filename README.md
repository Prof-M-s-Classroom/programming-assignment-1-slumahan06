[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

README Section (10 points total)
○ Explanation of each method (5 points)
○ Justification of Big-O complexity (5 points)

1. addWayPointAtBeginning()

   This function creates a new node with the given data. It sets the next pointer of the new node to the existing head, and then sets the head pointer to the new node. Increases the length of the list by one.

   This function has a time complexity of O(1) since instead of iterating through the entire list, it utilizes the existing head pointer to add to the start of the route.
2.