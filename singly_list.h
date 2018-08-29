#ifndef __SINGLY_LIST__H__
#define __SINGLY_LIST__H__

typedef struct student {
	int num;
	char name[32];
	struct student * next;
}STU;
extern void singly_list_add(STU **head ,STU *padd);
extern STU * singly_list_del(STU **head,int num);
extern int singly_list_node_count(STU * head);
extern void singly_list_sort(STU **head);

#endif
