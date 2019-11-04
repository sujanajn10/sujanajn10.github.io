#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
 
lint get_lint() { 
	lint n =0;
	register int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	return n;
}
void put_lint (lint li, char lc) {
	if (0 == li) {
		pcx('0'); if(lc) pcx(lc); return;
	}
	char s[24];
	auto idx =0;
	for (; li; idx++) {
		s[idx] = '0' + li % 10;
		li /= 10;
	}
	for (auto jdx=idx-1; jdx>=0; jdx--)
		pcx(s[jdx]);
	if(lc) pcx(lc);
}
 
int main () {
	lint N = get_lint();
	lint K = get_lint();
	int lSwitch [3][3] ={  {0, 1, 2},
	                        {2, 0, 1},
	                        {1, 2, 0}};
	int NTL[N+K+2];
	int lch;
    for(auto ni=1; ni<=N; ni++) {
        while (!isupper(lch = gcx()));
        if ('R' == lch) NTL[ni] = 1;
        else if ('Y' == lch) NTL[ni] = 2;
        else NTL[ni] = 0;
    }
	lint sTime =0;
    if (1==K) {
        for (auto ni=1; ni<=N; ni++)
            sTime += lSwitch[NTL[ni]][0];  
        put_lint(sTime, 0);
        return 0;
    }
	int sLog[N+K+2];   
	memset(sLog, 0, sizeof(sLog));
    
    lint kBlocks = N/K + ((N %K)? 1 : 0);
    for (auto ki=1; ki<=kBlocks; ki++) {
        lint kL = K*(ki-1) +1;
        lint kR = (ki*K > N) ? N : ki*K;
        if (ki>1) {
            for(auto ni=kL+1; ni<=kR; ni++)
                sLog[ni] += sLog[ni-1];
            for (auto ni=kL; ni<=kR; ni++)
                NTL[ni] = (NTL[ni] + sLog[ni]) % 3;
        }
        for (auto ni=kR; ni>kL; ni--) {
            lint sCnt = lSwitch[NTL[ni]][NTL[ni-1]];
            sTime += sCnt;
            sLog[ni+K] -= sCnt;
            sLog[kR+1] += sCnt;
        }
        sTime += lSwitch[NTL[kL]][0];
    }
    put_lint(sTime, 0);
	return 0;
}