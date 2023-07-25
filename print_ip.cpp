#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
auto func(T t)-> decltype(-t){
    std::vector<int> ans;
    int n=sizeof(t);
    int c = (1 << 8) -1;
    for(int i=0;i<n;i++){
        ans.push_back(t&c);
        t>>=8;
    }
    std::reverse(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout<<ans[i];
        if (i==ans.size()-1) break;
        std::cout<<".";
    }
    
    std::cout<<std::endl;
    return t;
}

template<typename T,typename Enable = typename std::enable_if<!std::is_same<T,std::string>::value,void>::type>
auto func(T t) -> decltype(t.size()){
    size_t i=0;
    for (auto v: t)
    {
        std::cout<<v;
        i++;
        if (i==t.size()) break;
        std::cout<<".";
    }
    
    std::cout<<std::endl;
    return 0;
}

template<typename T>
auto func(T t) ->decltype(t.length()){
    std::cout<<t<<std::endl;
    return 0;
}


int main()
{
    func(int8_t{-1});
    func(int16_t{0});
    func(int32_t{2130706433} );
    func(int64_t{8875824491850138409});
    func(std::string{"Hello World!"});
    func(std::vector<int>{100, 200, 300, 400} ); 
    func(std::list<short>{400, 300, 200, 100} ); 
}