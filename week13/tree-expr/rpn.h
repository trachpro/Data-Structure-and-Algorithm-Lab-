

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x== '^')
        return 3;
}



int checkOperator(char x){
  if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') {
    return 1;
  }
  else return 0;
}

void Traverse(stackType stack){
  Node *p = stack.top;
  while (p != NULL) {
    printf("%s    ",p -> data);
    p = p -> prev;
  }
  printf("\n");
}


void TraverseBottom(Node *p){
  if (p == NULL) {
    return;
  }
  TraverseBottom(p->prev);
  printf("%s   ",p->data);
}



stackType postfix(char exp[]) {
  char tmp[100]="",x[2]="";

  int i=0;

  exp[strlen(exp)] = ')';
  exp[strlen(exp)] = '\0';

  stackType stack,post;

  Initialize(&stack);
  Initialize(&post);

  push(&stack,"(");
  
  while ( !empty(&stack) ) {
    tmp[0] = '\0';

    if(isdigit(exp[i])){
      while (isdigit(exp[i])) {
        tmp[strlen(tmp)] = exp[i];
        i++;
      }
      push(&post,tmp);
      tmp[0] = '\0';
    }


     if(exp[i] == '(') push(&stack,"(");


     if ( checkOperator(exp[i]) == 1) {
      strcpy(tmp,Top(&stack));
      while ( priority(tmp[0]) >= priority(exp[i]) ) {
        push(&post,Top(&stack));
        pop(&stack);
        strcpy(tmp,Top(&stack));
      }
      tmp[0] = exp[i];
      tmp[1] = '\0';
      push(&stack,tmp);
      tmp[0] = '\0';
    }

    if (exp[i] == ')') {
      strcpy(x,Top(&stack));
      while ( strcmp(x,"(") != 0) {
          push(&post,pop(&stack));
          strcpy(x,Top(&stack));
        //pop(&stack);
      }

      if( strcmp(Top(&stack),"(") == 0) pop(&stack);
    }
    i++;
  }


  // printf("stack: \n");
  // Traverse(stack);
  // printf("Post: \n");
  // Traverse(post);
  // TraverseBottom(post.top);
  // printf("\n");
  return post;
}
