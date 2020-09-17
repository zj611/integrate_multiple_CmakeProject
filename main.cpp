#include <string>
#include <iostream>
#include "CJSON/CJsonObject.hpp"
#include "DownloadModule/HttpClient.h"

int main(int argc, char* argv[]){

    neb::CJsonObject oJson("");

    std::cout << oJson.ToString() << std::endl;

    oJson.AddEmptySubObject("depend");
    oJson["depend"].Add("nebula", "https");
    oJson["depend"].AddEmptySubArray("bootstrap");
    oJson["depend"]["bootstrap"].Add("BEACON");
    oJson["depend"]["bootstrap"].Add("hhhh");

    std::cout << oJson.ToString() << std::endl;

    //Download image files
    bool download_flag = false;
    HttpClient client;
    std::string image_url = "https://test-1301539759.cos.ap-guangzhou.myqcloud.com/public/huaping/993VA0104_20200725155144_10.jpg";
    auto pos = find(image_url.rbegin(), image_url.rend(), '/');
    string img_name = image_url.substr(distance(pos, image_url.rend()));

    std::string save_dir = "./";
    cout<<img_name<<endl;
    cout<<save_dir+img_name<<endl;

    download_flag = client.downloadAs(image_url,save_dir+img_name);
    if(download_flag)
        std::cout<< "["<<"download flag:"<<img_name << "]";
    else{
        std::cout<< "["<<"download flag:failed!]"<<std::endl;
        return -1;
    }
    return 0;
}

