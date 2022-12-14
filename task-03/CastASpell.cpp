#include <bits/stdc++.h>
using namespace std;


int main() {
    int spellcount, languagecount;
    cin>>spellcount>>languagecount;
    string magicalwords[languagecount], commonwords[languagecount], spell, spellarray[spellcount];
    
    for(int i=0; i < languagecount; i++) {
        cin>>magicalwords[i]>>commonwords[i];
    }
    for(int i=0; i < spellcount; i++) {
        cin>>spellarray[i];
    }
    
    string fastest = "";
    for(int i=0; i < spellcount; i++) {
        for(int j=0; j < languagecount; j++) {
            if(spellarray[i] == magicalwords[j]) {
               if(magicalwords[j].length() > commonwords[j].length())
                    fastest += commonwords[j];
               else
                    fastest += magicalwords[j];
               if(i != spellcount-1)
                    fastest += ' ';               
            }
        }
    }
    cout<<fastest<<"\n";
}
