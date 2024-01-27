// remember to print the list using bottom pointer not using next pointer
Node* merge(Node*&first, Node*&second){
	Node *temp = new Node(-1);
	Node *head = temp;
	while(first!=NULL&&second!=NULL){
		if(first->data<=second->data){
			temp->bottom = first;
			temp = first;
			first = first->bottom;
		}
		else{
			temp->bottom = second;
			temp = second;
			second= second->bottom;
		}
	}	
	while(first!=NULL){
		temp->bottom= first;
		temp = first;
		first = first->bottom;
	}
	while(second!=NULL){
		temp->bottom= second;
		temp = second;
		second = second->bottom;
	}
	return head->bottom;
}
Node* flatten(Node* head) 
{
	// Write your code here
	if(head==NULL){
		return head;
	}
	Node *first = head;
	Node *next = head->next;
	head->next = NULL;
	Node *second = flatten(next);

	Node*temp = merge(first,second);
	Node *prehead = temp;
	return prehead;
}
