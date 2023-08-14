#include"Double_Linked_List.h"

ret_Status_t Insert_Node_At_Beginning(node_t **Head)
{
    ret_Status_t ret = R_NOK ;
    node_t *TempNode = NULL ;

    TempNode = (node_t *)malloc(sizeof(node_t));
    if (!TempNode)
    {
        printf("Failing to create new node !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        printf("Enter data of first node : ");
        scanf("%i",&TempNode->NodeData);
        TempNode->LeftNodeLink = NULL;

        if (!(*Head)) /* Check if the list is empty */
        {
            TempNode->RightNodeLink=NULL;
        }
        else /* If the list is not empty */
        {
            TempNode->RightNodeLink= *Head ;
            (*Head)->LeftNodeLink = TempNode ;
        }
        *Head = TempNode ;
        ret = R_OK;
    }
    return ret ;
}

ret_Status_t Insert_Node_At_Last(node_t **Head)
{
    ret_Status_t ret = R_NOK ;
    node_t *TempNode = NULL ;
    node_t *TempNodeCount = *Head ;

    TempNode = (node_t *)malloc(sizeof(node_t));
    if (!TempNode)
    {
        printf("Failing to create new node !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        printf("Enter data of last node : ");
        scanf("%i",&TempNode->NodeData);
        TempNode->RightNodeLink = NULL;

        if (!(*Head)) /* Check if the list is empty */
        {
            TempNode->LeftNodeLink=NULL;
            *Head = TempNode ;
        }
        else /* If the list is not empty */
        {
            while(TempNodeCount->RightNodeLink)
            {
                TempNodeCount = TempNodeCount->RightNodeLink;
            }
            TempNodeCount->RightNodeLink = TempNode ;
            TempNode->LeftNodeLink = TempNodeCount ;
        }
        ret = R_OK;
    }
    return ret ;
}

ret_Status_t Insert_Node_In_Position(node_t *Head)
{
    ret_Status_t ret = R_NOK ;
    node_t *TempNode = NULL ;
    node_t *TempNodeCount = Head ;
    uint32 Length   = ZERO ;
    uint32 Position = ZERO;
    uint32 Count    = 1 ;  /* Points to the first node */

    Length = Get_Length(Head);
    printf("Enter Position of Insert Node (Exist %i Node in the list): ",Length);
    scanf ("%i",&Position);

    if (Length < Position)
    {
        printf("Invalid Position !! \n");
        ret = R_NOK ;
    }
    else if (Position == 1)
    {
        printf("Please use (Insert_Node_At_Beginning) !!\n");
    }
    else
    {
        TempNode =(node_t *)malloc(sizeof(node_t));
        if (!TempNode)
        {
            printf("Failing to create new node !! \n");
            ret = R_NULL_POINTER;
        }
        else
        {
            printf("Enter data of node : ");
            scanf("%i",&TempNode->NodeData);


            while( Count++ < (Position-1))
            {
                TempNodeCount = TempNodeCount->RightNodeLink;
            }

            TempNode->RightNodeLink = TempNodeCount->RightNodeLink;
            TempNode->LeftNodeLink  = TempNodeCount ;
            TempNodeCount->RightNodeLink = TempNode ;
            (TempNode->RightNodeLink)->LeftNodeLink = TempNode ;

            ret = R_OK;
        }
    }
    return ret ;
}

ret_Status_t Delete_Node_At_Beginning(node_t **Head)
{
    ret_Status_t ret = R_NOK ;
    node_t *TempNode = *Head ;

    if (!TempNode) /* Check if the list is empty */
    {
        printf("The list is empty !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        *Head = TempNode->RightNodeLink ;

        TempNode->LeftNodeLink  = NULL ;
        TempNode->RightNodeLink = NULL ;

        free(TempNode);
        TempNode = NULL ;
        ret = R_OK;
    }
    return ret ;
}

ret_Status_t Delete_Node(node_t *Head)
{
    ret_Status_t ret = R_NOK ;
    node_t *TempNode = Head ;
    node_t *TempNodeCount = Head ;
    uint32 Length   = ZERO ;
    uint32 Position = ZERO;
    uint32 Count    = 1 ;  /* Points to the first node */

    if (!TempNode)
    {
        printf("The list is empty, nothing to be deleted !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        Length = Get_Length(Head);
        printf("Enter Position of Node to be delete (Exist %i Node in the list): ",Length);
        scanf ("%i",&Position);

        if (Length < Position)
        {
            printf("Invalid Position !! \n");
            ret = R_NOK ;
        }
        else
        {
            if (Position == 1)
            {
                printf("Please use (Delete_Node_At_Beginning) !!\n");
            }
            else
            {
                while(Count++ < (Position-1))
                {
                    TempNodeCount = TempNodeCount->RightNodeLink;
                }

                TempNode = TempNodeCount->RightNodeLink;
                TempNodeCount->RightNodeLink = TempNode->RightNodeLink;

                if (TempNode->RightNodeLink) /*Check if deleted node is not last node*/
                    (TempNode->RightNodeLink)->LeftNodeLink = TempNodeCount->RightNodeLink;

                TempNode->LeftNodeLink  = NULL ;
                TempNode->RightNodeLink = NULL ;
                free(TempNode);
                TempNode = NULL ;
                ret = R_OK;
            }
        }
    }
    return ret ;
}

ret_Status_t Display_All_Nodes(node_t *Head)
{
    ret_Status_t ret = R_NOK;
    node_t *TempNode = Head  ;

    if (!Head)
    {
        printf("The list is empty !! \n");
        ret = R_OK;
    }
    else
    {
        printf("Element of list ");
        while(TempNode)
        {
            printf("=> %i ",TempNode->NodeData);
            TempNode = TempNode->RightNodeLink;
        }
        printf("\n");
        ret = R_OK ;
    }
    return ret ;
}

ret_Status_t Display_All_Nodes_Reverse(node_t *Head)
{
    ret_Status_t ret = R_NOK;
    node_t *TempNode = Head  ;

    if (!Head)
    {
        printf("The list is empty !! \n");
        ret = R_OK;
    }
    else
    {
        printf("Element of list ");
        while(TempNode->RightNodeLink)
        {
            TempNode = TempNode->RightNodeLink ;
        }
        while(TempNode)
        {
            printf("=> %i ",TempNode->NodeData);
            TempNode = TempNode->LeftNodeLink;
        }
        printf("\n");
        ret = R_OK ;
    }
    return ret ;
}

uint16 Get_Length(node_t *Head)
{
    node_t *TempNode = Head ;
    uint16 Count = ZERO ;

    if (!Head)
    {
        Count = ZERO;
    }
    else
    {
        while(TempNode)
        {
            TempNode =TempNode->RightNodeLink ;
            Count++;
        }
    }
    return Count ;
}
