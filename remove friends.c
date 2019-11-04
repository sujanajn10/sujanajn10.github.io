#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
 
lint getl () {
	lint n =0;
	register int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	return n;
}
void putl (lint li, char lc) {
	if (0 == li) {
		pcx('0'); if(lc) pcx(lc); return;
	}
	char s[24]; lint idx =-1;
	while (li) {
		s[++idx] = '0' + li % 10;
		li /= 10;
	}
	for (lint jdx=idx; jdx>=0; --jdx) pcx(s[jdx]);
	if(lc) pcx(lc);
}
typedef struct lln {
    lint val;
    struct lln* prv;
    struct lln* nxt;
} LL_t;
 
// Double-Linked-List was used (practice problem)
int main () {
    LL_t *NPH = (LL_t*) malloc (100000 * sizeof(LL_t));
 
	lint T = getl() +1;
	while(--T) {
        lint F = getl();
        lint D = getl();
        
        lint NID =0;
        LL_t *fHead = NPH + NID++;
        fHead->val = getl();
        fHead->prv = NULL;
        LL_t *cNode = fHead;
        for (lint fid=1; fid<F; ++fid) {
            LL_t* node = NPH + NID++;
            node->val = getl();
            node->prv = cNode;
            cNode->nxt = node;
            cNode = node;
        } cNode->nxt =NULL;
        cNode = fHead; 
        while (D > 0) {
            if (!cNode->nxt) {
                cNode = cNode->prv;
                cNode->nxt = NULL;
                --D;
            } else if (cNode->val < (cNode->nxt)->val) { 
                if (cNode->prv) {
                    (cNode->prv)->nxt = cNode->nxt;
                    (cNode->nxt)->prv = cNode->prv;
                    cNode = cNode->prv;
                } else {
                    fHead = cNode->nxt;
                    fHead->prv = NULL;
                    cNode = fHead;
                }
                --D;
            } else //move
                cNode = cNode->nxt;
        } 
        for (LL_t*node=fHead; node; node=node->nxt)
            putl(node->val, ' ');
        pcx('\n');
	}
	return 0;
}