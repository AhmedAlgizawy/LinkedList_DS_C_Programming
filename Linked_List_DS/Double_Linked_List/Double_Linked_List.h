#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

#include <stdlib.h>
#include "Platform_Types.h"

typedef struct node{
    uint32 NodeData ;
    struct node *LeftNodeLink;
    struct node *RightNodeLink;
}node_t;

typedef enum{
    R_NOK,
    R_OK,
    R_NULL_POINTER
}ret_Status_t;

/**@brief Insert node At beginning.
  *@param (Head) Pointer to pointer to head address of list.
  *@retval Status of function operation.
  */
ret_Status_t Insert_Node_At_Beginning(node_t **Head);

/**@brief Insert node At last.
  *@param (Head) Pointer to pointer to head address of list.
  *@retval Status of function operation.
  */
ret_Status_t Insert_Node_At_Last(node_t **Head);

/**@brief Insert node At any position.
  *@param (Head) Pointer to pointer to head address of list.
  *@retval Status of function operation.
  */
ret_Status_t Insert_Node_In_Position(node_t *Head);

/**@brief Delete node At beginning.
  *@param (Head) Pointer to pointer to head address of list.
  *@retval Status of function operation.
  */
ret_Status_t Delete_Node_At_Beginning(node_t **Head);

/**@brief Delete node At any position.
  *@param (Head) Pointer to pointer to head address of list.
  *@retval Status of function operation.
  */
ret_Status_t Delete_Node(node_t *Head);

/**@brief Display all elements of list.
  *@param (Head) Pointer to head address of list.
  *@retval Status of function operation.
  */
ret_Status_t Display_All_Nodes(node_t *Head);

/**@brief Display reverse all elements of list.
  *@param (Head) Pointer to head address of list.
  *@retval Status of function operation.
  */
ret_Status_t Display_All_Nodes_Reverse(node_t *Head);


/**@brief Determine the length of list.
  *@param (Head) Pointer to head address of list.
  *@retval Status of function operation.
  */
uint16 Get_Length(node_t *Head);


#endif // _DOUBLE_LINKED_LIST_H

