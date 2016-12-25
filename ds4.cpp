#if __INCLUDE_LEVEL__ == 1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#else
#include "ds4.cpp"
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set verygood;

int val=0;

int n,m,t;
char ch;

int ans=0;

int main(){
    scanf("%d%d",&n,&m);
    while (n--) {
        scanf("%d",&t);
        verygood.insert({t,val++});
    }
    while (m--) {
        scanf(" %c",&ch);
        scanf("%d",&t);t^=ans;
        if (ch=='I') {
            verygood.insert({t,val++});
        }
        else if (ch=='R') {
            if (verygood.lower_bound({t,0})->first==t) {
                verygood.erase(verygood.lower_bound({t,0}));
            }
        }
        else if (ch=='S') {
            if (t>verygood.size()) {
                ans=-1;
            }
            else {
                ans=verygood.find_by_order(t-1)->first;
            }
            printf("%d\n",ans);
        }
        else {
            if (verygood.lower_bound({t,0})->first==t) {
                ans=verygood.order_of_key(*verygood.lower_bound({t,0}))+1;
            }
            else ans=-1;
            printf("%d\n",ans);
        }
    }
    for (pair<int,int> i:verygood) printf("%d ",i.first);
}
#endif
