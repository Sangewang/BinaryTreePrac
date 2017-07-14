/*********************************************************
Description   :   BinaryTree
History       :   

Date          :   2017/07/14
Author        :   wangzai
Modificatipon :
*********************************************************/
#include <stdio.h>
#include <malloc.h>

typedef struct binarytreenode
{
  char   m_Value;
  struct binarytreenode *m_pLeftChild;
  struct binarytreenode *m_pRightChild;
}BinaryTreeNode;


/*********************************************************
Description   :   CreateBinaryTree  
Input         :   BinaryTreeNode ** pRoof
Output        :   void
Return Value  :   void
Calls         :
Called By     :
*********************************************************/
void CreateBinaryTree(BinaryTreeNode **pRoof)
{
  char value;
  value = getchar();
  printf("value = %d\n",value);
  if((int)value==10)
  {
    scanf("%c",&value);
  }
  if(value=='#')
  {
    *pRoof = NULL;
    return;
  }
  else
  {
    *pRoof = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    (*pRoof)->m_Value = value;
    CreateBinaryTree(&((*pRoof)->m_pLeftChild));
    CreateBinaryTree(&((*pRoof)->m_pRightChild));
  }
}

/*********************************************************
Description   :   ShowBinaryTree  
Input         :   BinaryTreeNode * pRoof
Output        :   void
Return Value  :   void
Calls         :
Called By     :
*********************************************************/
void ShowBinaryTree(BinaryTreeNode *pRoof)
{
  if(NULL != pRoof)
  {
    printf("%c ",pRoof->m_Value);
  }
}


/*********************************************************
Description   :   PreOrder 
Input         :   BinaryTreeNode * pRoof
Output        :   void
Return Value  :   void
Calls         :
Called By     :
*********************************************************/
void PreOrder(BinaryTreeNode *pRoof)
{

  if(NULL!=pRoof)
  {
    ShowBinaryTree(pRoof);
    PreOrder(pRoof->m_pLeftChild);
    PreOrder(pRoof->m_pRightChild);
  }
}

int main()
{
  BinaryTreeNode * pRoof = NULL;
  CreateBinaryTree(&pRoof);
  PreOrder(pRoof);
  printf("\n");
}
