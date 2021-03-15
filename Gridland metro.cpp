int gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
     long long res=0;
     long long tot=n*m;

     unordered_map<int,set<pair<int,int>>> um;

     for(auto a : track) {
            um[a[0]].insert({a[1],a[2]});
     }
     
     
     for(auto a : um) {
         
         cout<<a.first<<" ";
         for(auto b : a.second) {
             cout<<"{ "<<b.first<<","<<b.second<<" }";
         }
         cout<<endl;
     }
        cout<<endl; 
    
     for(auto a :um) {
           auto itr1=a.second.begin();
           int ck1=itr1->first;
           int ck2=itr1->second;
           itr1++;
          // cout<<ck1<<" "<<ck2<<endl;
           for(auto &itr = itr1; itr != a.second.end(); itr++) {
               if(itr->first <= ck2) {
                   //cout<<ck2<<" "<<endl;
                   ck2 = max(ck2,itr->second);
                  // cout<<ck2<<" ";
               } else {
                   res+=(ck2-ck1)+1;
                   ck1=itr->first;
                   ck2=itr->second;
               }
           }
              res+=(ck2-ck1)+1;
     }
     
    
     return tot-res;
}
