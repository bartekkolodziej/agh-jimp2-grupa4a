//
// Created by bartek on 09.05.17.
//

#include <Serialization.h>

using ::academia::Building;
using ::academia::Room;
using ::academia::Serializer;
using ::academia::Serializable;
using ::academia::XmlSerializer;
using ::academia::JsonSerializer;
using ::academia::MockSerializer;
using ::academia::BuildingRepository;


using namespace std;
using namespace std::literals;



int main(){
        BuildingRepository repository{};
MockSerializer serializer;
std::vector<std::reference_wrapper<const Serializable>> empty;

repository.StoreAll(&serializer);
}