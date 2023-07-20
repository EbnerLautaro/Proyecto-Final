/**
*  @file list.h
*  @brief TAD list definition
*/
#ifndef __list_H__
#define __list_H__
#include <stdbool.h>

typedef unsigned int u32;

/**
* @brief list type definition
*/
typedef struct _s_list *list;

/**
* @brief list elements type definition
*/
typedef  u32 list_elem;

/**
* @brief Creates an empty list
* @return An empty list
*/
list list_empty();

/**
* @brief Inserts an element at the top of the list
* @param s A list
* @param e An element to push into the list
* @return The new list with 'e' at the top
*/
list list_push(list s, list_elem e);

/**
* @brief search for elem in the list
* @param s A list
* @param index index of the required element
* @return the elem at the index position
*/
list_elem list_by_index(list s, u32 index);
void list_change_elem(list s, u32 index, u32 newName); //changes the name of the indexed vecino

/**
* @brief Removes the element at the top of the list
* @param s A list
* @return The new list with the top element removed
* @note Only applies to non-empty lists
*/
list list_pop(list s);

/**
* @brief Returns the size of the list
* @param s A list
* @return The size of the list
*/
unsigned int list_size(list s);

/**
* @brief Returns the element at the top of the lists
* @param s A lists
* @return The element at the top of the list
* @note Only applies to non-empty lists
*/
list_elem list_top(list s);

/**
* @brief Check if the given list is empty
* @param s A list
* @return true if the list is empty, false otherwise
*/
bool list_is_empty(list s);

/**
* @brief Creates an array with all the elements of the list
* @param s A list
* @return An array containing all the elements of the list. The list top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'list_size(s)'
*/
list_elem *list_to_array(list s);

/**
* @brief Destroys the list
* @param s A list
* @note All memory resources are freed
*/
list list_destroy(list s);


#endif
