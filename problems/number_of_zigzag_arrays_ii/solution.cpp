#define ll long long int
// #define mod 1e9+7   this is evaluated to double
#define mod 1000000007

class Solution {
    private:
    // matrix multiplication helper
    vector<vector<ll>>multiply(vector<vector<ll>>&a , vector<vector<ll>>&b){
        int n = a.size();
        vector<vector<ll>>c(n,vector<ll>(n,0));
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(a[i][k] == 0) continue;

                for(int j=0;j<n;j++){
                    if(b[k][j] == 0) continue;
                    c[i][j] = (c[i][j]%mod + (a[i][k]%mod * b[k][j]%mod)%mod)%mod;
                }
            }
        }
        return c;

    }
// exponent finding function
    vector<vector<ll>>power(vector<vector<ll>>base , long long exp){
        int n = base.size();
        vector<vector<ll>>result(n,vector<ll>(n,0));
        for(int i=0;i<n;i++){
            result[i][i] = 1;
        }
        while(exp>0){
            // odd case
            if(exp%2==1){
                result = multiply(result,base);
            }
            // for evens we simply square
            base = multiply(base,base);
            exp = exp/2;

        }
        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;
        int s = 2*m;

// lambda function
        auto U = [&](int v){
            return v-1;
        };
        auto D = [&](int v){
            return (m+v-1);
        };
        // transition matrix for matrix exponentation
        vector<vector<ll>>transition(s,vector<ll>(s,0));
// we will be reserving the first m places for UPs and next m for DOWNs of the 2*m sized array(m ups+m downs)

        for(int v = 1; v <= m; v++){
            for(int u=1;u<v;u++){
                transition[U(v)][D(u)] = 1;
            }
            for(int u = v+1;u<=m;++u){
                transition[D(v)][U(u)] = 1;
            }
        }
        // forming the 2 size ans manually
        vector<ll>dp2(s,0);
        for(int v=1;v<=m;v++){
            dp2[U(v)] = v-1;     // the previous operation must be down
            dp2[D(v)] = m-v;     // the previous operation must be up
        }
        vector<vector<ll>>recurrence_matrix = power(transition , n-2);
        vector<long long>dpn(s,0);  // for the n size recursive dp

        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                dpn[i] = (dpn[i] + recurrence_matrix[i][j]*dp2[j])%mod;
                // multiplying the recurrence relation
                // n_size = T^n-2 * 2_size
            }
        }
        long long ans = 0;
        for(auto x:dpn){
            ans = (ans+x)%mod;
        }
        return ans;
    }
};