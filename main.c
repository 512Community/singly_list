#include <stdio.h>
#include <stdlib.h>
#include <singly_list.h>
STU * head = NULL;
void print (STU *head) {
	while(head) {
		printf("num:%d name:%s\n", head->num, head->name);
		head = head->next;
	}
}

void delete(STU **head) {
	int num;

	scanf("%d",&num);
	free(singly_list_del(head, num));
	print(*head);
}
void add(STU **head) {
	STU * p;

	p=malloc(sizeof(*p));
	scanf("%d %s", &p->num, p->name);
	print(singly_list_add(head, p));
}

void sort(STU ** head)
{
	print(singly_list_sort(head));
}

int main(int argc, const char *argv[])
{
	while (1) {
		printf("add:1 delete:2 print:3 sort:4 exit:x\n");
		int x=0;
		scanf("%d",&x);
		switch (x) {
			case 1:
				add(&head);
				break;
			case 2:
				delete(&head);
				break;
			case 3:
				print(head);
				break;
			case 4:
				sort(&head);
				break;
			default:
				return 0;
		}

	}
	return 0;
}
