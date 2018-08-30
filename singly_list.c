#include <stdio.h>
#include <singly_list.h>

STU * singly_list_add(STU **head ,STU *padd)
{
	STU **curr;

	for(curr = head; *curr; curr = &(*curr)->next) {
#ifdef __SORT
		if ((*curr)->num > padd->num)
			break;
#endif
	}

	padd->next = *curr;
	*curr = padd;

	return *head;
}

STU * singly_list_del(STU **head,int num)
{
	STU **curr;
	STU *entry;

	for(curr = head; *curr; curr = &(*curr)->next) {
		entry = *curr;
		if (entry->num == num) {
			*curr = entry->next;
			goto out;
		}
	}

	entry = NULL;
out:
	return entry;
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
	STU *entry;

	count = singly_list_node_count(*head);
	if(count < 1)
		goto out;

	for (i = 0; i < count -1; i++) {
		for (curr = head; *curr && (*curr)->next; curr = &(*curr)->next) {
			entry = *curr;
			if(entry->num > entry->next->num) {
				*curr = entry->next;
				entry->next = (*curr)->next;
				(*curr)->next = entry;
			}
		}
	}

out:
	return *head;
}
