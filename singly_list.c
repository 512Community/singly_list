#include <stdio.h>
#include <singly_list.h>

STU * singly_list_add(STU **head ,STU *padd)
{
	STU **curr = head;

	while(*curr) {
		/*
		if ((*curr)->data > padd->data)
			break;
		*/
		curr = &(*curr)->next;
	}

	padd->next = *curr;
	*curr = padd;

	return *head;
}

STU * singly_list_del(STU **head,int num)
{
	STU **curr = head;

	while(*curr) {
		STU *entry = *curr;
		if (entry->num == num) {
			*curr = entry->next;
			//free(entry);
			return entry;
		} else {
			curr = &entry->next;
		}
	}

	return NULL;
}

int singly_list_node_count(STU * head)
{
	int count ;
	for (count = 0; head; count++) {
		head = head->next;
	}

	return count;

}

STU * singly_list_sort(STU **head)
{
	int i;
	int count;
	STU **curr;

	count = singly_list_node_count(*head);
	if(count < 1)
		goto out;

	for (i = 0; i < count -1; i++) {
		curr = head;
		while (*curr && (*curr)->next) {
			STU *entry = *curr;
			if(entry->num > entry->next->num) {
				*curr = entry->next;
				entry->next = (*curr)->next;
				(*curr)->next = entry;
			}

			curr = &(*curr)->next;
		}
	}

out:
	return *head;
}
