#include <stdio.h>
#include <stdlib.h>

#include "Single_Linked_List.h"

node_t *ListHead = NULL ;
uint16 Length = ZERO ;
int main()
{
    ret_Status_t Ret = R_NOK ;
    uint8 UserChoice = 0;

    printf("-> Hello to Single Linked List. \n");
    printf("-> Choose number to operating the function. \n");

    printf("\n===============================\n");
    printf("-> 1 ) Insert_Node_At_Beginning \n");
    printf("-> 2 ) Insert_Node_At_Last \n");
    printf("-> 3 ) Insert_Node_In_Position \n");
    printf("-> 4 ) Delete_Node_At_Beginning \n");
    printf("-> 5 ) Delete_Node \n");
    printf("-> 6 ) Reverse_List \n");
    printf("-> 7 ) Swap_Two_Node \n");
    printf("-> 8 ) Sort_List \n");
    printf("-> 9 ) Display_All_Nodes \n");
    printf("-> 10) Reverse_Display_All_Nodes \n");
    printf("-> 11) Get_Length \n");
    printf("-> 12) Exit from application \n");
    printf("===============================\n");

    while(1)
    {
        printf("\nUserChoice : ");
        scanf("%i", &UserChoice);

        switch (UserChoice)
        {
        case 1:
            Ret = Insert_Node_At_Beginning (&ListHead);
            break;

        case 2:
            Ret = Insert_Node_At_Last (&ListHead);
            break;

        case 3:
            Ret = Insert_Node_In_Position (&ListHead);
            break;

        case 4:
            Ret = Delete_Node_At_Beginning (&ListHead);
            if (Ret == R_OK)
            {
                printf("First node is deleted.\n");
            }
            break;

        case 5:
            Ret = Delete_Node (&ListHead);
            break;

        case 6:
            Ret = Reverse_List (&ListHead);
            break;

        case 7:
            Ret = Swap_Two_Node (ListHead);
            break;

        case 8:
            Ret = Sort_List (ListHead);
            break;

        case 9:
            Ret = Display_All_Nodes (ListHead);
            break;

        case 10:
            Ret = Reverse_Display_All_Nodes (ListHead);
            break;

        case 11:
            Length = Get_Length(ListHead);
            printf ("Length of linked list = %i \n",Length);
            break;

        case 12:
            printf("Exit from application \n");
            exit(1);
            break;

        default:
            printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;
}
