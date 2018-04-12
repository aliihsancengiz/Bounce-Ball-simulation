#ifndef listdata
#define	listdata
#include<stdio.h>
#include<stdlib.h>
#include "ball_function.h"
struct list{
	float btime;
	float xposball;
	float yposball;
	float vball;
	float kball;
	float pball;
	char sball;
	struct list * link;
}; 
typedef struct list node;
void display(node *r){
	node *temp=r;
	int i=0;
	printf("Hello from node 1...\n",++i);
	while(r->link!=NULL){
		printf("Hello from node %d...\n",++i);
		r=r->link;
	}
}
node *add(node *r,struct real_t *ballf){
	if(r==NULL){
		node *temp=(node*)malloc(sizeof(node));
		temp->kball=ballf->k_energy;
		temp->pball=ballf->p_energy;
		temp->sball=ballf->direction;
		temp->vball=ballf->velocity;
		temp->xposball=ballf->xpos;
		temp->yposball=ballf->ypos;
		temp->btime=ballf->time;
		temp->link=NULL;
		return temp;
	}
	if(r->link==NULL){
		node *temp=(node*)malloc(sizeof(node));
		temp->kball=ballf->k_energy;
		temp->pball=ballf->p_energy;
		temp->sball=ballf->direction;
		temp->vball=ballf->velocity;
		temp->xposball=ballf->xpos;
		temp->yposball=ballf->ypos;
		temp->btime=ballf->time;
		temp->link=NULL;
		r->link=temp;
		return r;
	}
	node *temp=r;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link=(node*)malloc(sizeof(node));
	temp->link->kball=ballf->k_energy;
	temp->link->pball=ballf->p_energy;
	temp->link->sball=ballf->direction;
	temp->link->vball=ballf->velocity;
	temp->link->xposball=ballf->xpos;
	temp->link->yposball=ballf->ypos;
	temp->btime=ballf->time;
	temp->link->link=NULL;
	return r;
}




#endif
