#include "Single_Linked_List.h"

ret_Status_t Insert_Node_At_Beginning(node_t **Head)
{
    ret_Status_t ret = R_NOK;
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

        if (*Head)  /* Check if linked list is not empty */
        {
            TempNode->NodeLink = *Head;
        }
        else   /* Check if linked list is empty */
        {
            TempNode->NodeLink = NULL;
        }
        *Head = TempNode;
        ret = R_OK;
    }
    return ret ;
}

ret_Status_t Insert_Node_At_Last(node_t **Head)
{
    ret_Status_t ret = R_NOK;
    node_t *TempNode = NULL ;
    node_t *TempNodeLast = NULL ;

    TempNode = (node_t *)malloc(sizeof(node_t));

    if (!TempNode)
    {
        printf("Failing to create new node !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        printf("Enter data of last node  : ");
        scanf("%i",&TempNode->NodeData);

        TempNode->NodeLink = NULL;

        if (!(*Head))  /* Check if linked list is empty */
        {
            *Head = TempNode;
        }
        else   /*If linked list is not empty */
        {
            TempNodeLast = *Head ;
            while(TempNodeLast->NodeLink)
            {
                TempNodeLast = TempNodeLast->NodeLink ;
            }

            TempNodeLast->NodeLink = TempNode ;
        }
        ret = R_OK;
    }
    return ret ;
}

ret_Status_t Insert_Node_In_Position(node_t **Head)
{
    ret_Status_t ret = R_NOK;
    node_t *TempNode = NULL ;
    node_t *TempNodeCount = NULL ;
    uint32 Length = ZERO ;
    uint32 Position = ZERO;
    uint32 Count = 1 ;  /* Points to the first node */

    Length = Get_Length(*Head);
    printf("Enter Position of Insert Node (Exist %i Node in the list): ",Length);
    scanf ("%i",&Position);

    if (Length < Position)
    {
        printf("Invalid Position !! \n");
        ret = R_NOK ;
    }
    else
    {
        TempNode = (node_t *)malloc(sizeof(node_t));

        if (!TempNode)
        {
            printf("Failing to create new node !! \n");
            ret = R_NULL_POINTER;
        }
        else
        {
            printf("Enter data of node : ");
            scanf("%i",&TempNode->NodeData);

            if (Position == 1)
            {
                TempNode->NodeLink = *Head;
                *Head = TempNode ;
            }
            else
            {
                TempNodeCount = *Head ;
                while(Count++<(Position-1))
                {
                    TempNodeCount=TempNodeCount->NodeLink;
                }
                TempNode->NodeLink=TempNodeCount->NodeLink;
                TempNodeCount->NodeLink = TempNode ;
            }
            ret = R_OK;
        }
    }
    return ret ;
}

ret_Status_t Delete_Node_At_Beginning(node_t **Head)
{
    ret_Status_t ret = R_NOK;
    node_t *TempNode = *Head ;

    if (!(*Head))
    {
        printf("The list is empty, nothing to be deleted !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        *Head = TempNode->NodeLink ;
        TempNode->NodeLink =NULL;
        free(TempNode);
        TempNode=NULL;
        ret = R_OK ;
    }
    return ret;
}

ret_Status_t Delete_Node(node_t **Head)
{
    ret_Status_t ret = R_NOK;
    node_t *TempNode = *Head ;
    node_t *TempNodeCount = NULL ;
    uint32 Length = ZERO ;
    uint32 Position = ZERO;
    uint32 Count = 1 ;  /* Points to the first node */

    if (!TempNode)
    {
        printf("The list is empty, nothing to be deleted !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        Length = Get_Length(*Head);
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
                *Head = TempNode->NodeLink ;
            }
            else
            {
                TempNodeCount = *Head ;
                while(Count++<(Position-1))
                {
                    TempNodeCount=TempNodeCount->NodeLink;
                }
                TempNode=TempNodeCount->NodeLink ;
                TempNodeCount->NodeLink = TempNode->NodeLink ;
            }

            TempNode->NodeLink =NULL;
            free(TempNode);
            TempNode=NULL;
            ret = R_OK;
        }
    }
    return ret ;
}

ret_Status_t Reverse_List(node_t **Head)
{
    ret_Status_t ret    =  R_NOK ;
    node_t *PrevNode    =  NULL ;
    node_t *CurrentNode = *Head ;
    node_t *NextNode    =  NULL ;

    if (!(*Head))
    {
        printf("The list is empty !! \n");
        ret = R_OK;
    }
    else
    {
        while (CurrentNode)
        {
            /*To store next node*/
            NextNode = CurrentNode->NodeLink;

            /*To reverse (NodeLink)*/
            CurrentNode->NodeLink = PrevNode ;

            /*Step to next node*/
            PrevNode    = CurrentNode;
            CurrentNode = NextNode ;
        }
        *Head = PrevNode ; /*Change the head for point to last node*/
        ret = R_OK ;
    }
    return ret ;
}

ret_Status_t Swap_Two_Node(node_t *Head)
{
    ret_Status_t ret   =  R_NOK;
    node_t *TempNode   =  NULL ;
    node_t *FirstNode  =  Head ;
    node_t *SecondNode =  NULL ;
    uint32 Length = ZERO ;
    uint32 Position = ZERO;
    uint32 Count = 1 ;  /* Points to the first node */

    if (!Head)
    {
        printf("The list is empty, nothing to be Swapped !! \n");
        ret = R_NULL_POINTER;
    }
    else
    {
        Length = Get_Length(Head);
        printf("Enter Position of Node to be swap with next node (Position of last node is (%i) ) : ",Length);
        scanf ("%i",&Position);

        if (Length <= Position)
        {
            printf("Invalid Position !! \n");
            ret = R_NOK ;
        }
        else
        {
            TempNode = (node_t *)malloc(sizeof(node_t *));
            if (TempNode)
            {
                while(Count++ < Position) /*Move To first node to be swap*/
                {
                    FirstNode = FirstNode->NodeLink;
                }

                SecondNode = FirstNode->NodeLink;  /*Select The second node to be swap*/

                /*Swap Two Node*/
                TempNode->NodeData = FirstNode->NodeData;
                FirstNode->NodeData = SecondNode->NodeData;
                SecondNode->NodeData = TempNode->NodeData;

                free(TempNode);
                TempNode = NULL ;
                ret = R_OK ;
            }
            else
            {
                printf("Error !!\n");
                ret = R_NOK ;
            }
        }
    }
    return ret ;
}

ret_Status_t Sort_List(node_t *Head)
{
    ret_Status_t ret = R_NOK ;
    node_t *TempNodeMax   = Head ;
    node_t *TempNodeCount = Head ;
    node_t *TempNode      = NULL ;
    uint32 Length = ZERO;
    uint32 Count  = ZERO;


    if (!(Head))
    {
        printf("The list is empty, nothing to be sorted !! \n");
        ret = R_OK;
    }
    else
    {
        Length=Get_Length(Head);


        TempNode = (node_t *)malloc(sizeof(node_t *)); /*Helper node to swap two data*/

        for(Count = ZERO ; Count < Length ; Count++)
        {
            while(TempNodeCount)
            {
                if ( TempNodeMax->NodeData < (TempNodeCount->NodeData))
                {
                    TempNode->NodeData = TempNodeMax->NodeData;
                    TempNodeMax->NodeData = TempNodeCount->NodeData ;
                    TempNodeCount->NodeData = TempNode->NodeData;
                }

                TempNodeCount = TempNodeCount->NodeLink;
            }
            TempNodeCount = TempNodeMax->NodeLink;
            TempNodeMax = TempNodeMax->NodeLink;
        }

        free(TempNode);  /*Free helper node from memory*/
        TempNode = NULL ;
        ret = R_OK;
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
            TempNode = TempNode->NodeLink;
        }
        printf("=> NULL\n");
        ret = R_OK ;
    }
    return ret ;
}

ret_Status_t Reverse_Display_All_Nodes(node_t *Head)
{
    ret_Status_t ret = R_NOK ;
    node_t *TempNode = NULL ;
    uint16 Num_Of_Elem = ZERO , Count = ZERO , Count_1 =ZERO ;

    if (!Head)
    {
        printf("The list is empty !! \n");
        ret = R_OK;
    }
    else
    {
        Num_Of_Elem = Get_Length(Head);

        printf("Element of list ");
        for (Count = 1 ; Count<=Num_Of_Elem ; Count++)
        {
            Count_1 = Num_Of_Elem-Count ;
            TempNode = Head ;

            while (Count_1--)
            {
                TempNode = TempNode->NodeLink ;
            }

            printf("=> %i ",TempNode->NodeData);
        }
        printf("=> NULL\n");
        ret = R_OK;
    }
    return ret ;
}

uint16 Get_Length(node_t *Head)
{
    node_t *TempNode = Head ;
    uint16 Count = ZERO ;

    if (!Head)
    {
        Count = ZERO ;
    }
    else
    {
        while(TempNode)
        {
            TempNode = TempNode->NodeLink;
            Count++;
        }
    }
    return Count ;
}
