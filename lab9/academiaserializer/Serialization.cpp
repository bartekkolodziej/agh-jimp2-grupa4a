//
// Created by bartek on 09.05.17.
//

#include "Serialization.h"

namespace academia {

    //Constructors:

    Room::Room(int id, std::string name,Type type){
        this->id = id;
        this->name = name;
        this->type = type;
    };


    Building::Building(int id, std::string name, std::vector<Room> rooms) {
        this->id = id;
        this->name = name;
        for (auto x: rooms) {
            this->rooms.emplace_back(x);
        }
    }

    BuildingRepository::BuildingRepository( std::initializer_list<Building> buildings){
       for (auto x : buildings) {
            this->buildings.push_back(x);
       }
   }

    // BuildingRepository functions:

    void BuildingRepository::Add(const Building &building){
        this->buildings.push_back(building);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const{
        std::experimental::optional<Building> new_building;
        for(auto &building : buildings){
            if (building.id == id) {
                new_building.emplace(building);
                return new_building;
            }
        }
    }


    // Json Serialization:
    //1. Serializators:

    void BuildingRepository::StoreAll(JsonSerializer* serializer)const{
        std::vector<std::reference_wrapper<const Serializable>> buildings_wrapped(buildings.begin(), buildings.end());
        (*serializer->output) << "{";
        serializer->ArrayField("buildings", buildings_wrapped);
        (*serializer->output) << "}";

    }

    void Room::Serialize(JsonSerializer *serializer) const {

        (*serializer->output) << "{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << ", ";
        serializer->StringField("type",Typ(type));
        (*serializer->output) << "}";

    }

    void Building::Serialize(JsonSerializer* serializer) const{
        std::vector<std::reference_wrapper<const Serializable>> rooms_wrapped(rooms.begin(), rooms.end());
        (*serializer->output) << "{";
        serializer->IntegerField("id", id);
        (*serializer->output) << ", ";
        serializer->StringField("name", name);
        (*serializer->output) << ", ";
        serializer->ArrayField("rooms", rooms_wrapped);
        (*serializer->output) << "}";
    }

    //2. Functions:

    void JsonSerializer::Header(const std::string &object_name){
        (*output) << "\"" <<  object_name << "\": [";
    }

    void JsonSerializer::Footer(const std::string &object_name){
        (*output) << "]";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*output) << "\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        (*output) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        (*output) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        (*output) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        JsonSerializer serializer(output);
        value.Serialize(&serializer);
    }

    void JsonSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value) {
        this->Header(field_name);
        bool IsFirst = true;
        for ( const Serializable &element:value) {
            if(!IsFirst)(*output)<< ", ";
            else IsFirst = false;
            element.Serialize(this);
        }
        this->Footer(field_name);
    }

    //Xml Serialization:
    //1. Serializators:

    void Room::Serialize(XmlSerializer *serializer) const {

        serializer->Header("room");
        serializer->IntegerField("id", id);
        serializer->StringField("name",name);
        serializer->StringField("type", Typ(type));
        serializer->Footer("room");

    }

    void Building::Serialize(XmlSerializer* serializer) const {
        std::vector<std::reference_wrapper<const Serializable>> rooms_wrapped(rooms.begin(), rooms.end());
        serializer->Header("building");
        serializer->IntegerField("id", id);
        serializer->StringField("name",name);
        serializer->ArrayField("rooms", rooms_wrapped);
      
        serializer->Footer("building");
    }

    void BuildingRepository::StoreAll(XmlSerializer* serializer)const{
        std::vector<std::reference_wrapper<const Serializable>> buildings_wrapped(buildings.begin(), buildings.end());
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", buildings_wrapped);
        serializer->Footer("building_repository");

    }


    void BuildingRepository::StoreAll(Serializer* serializer)const{
        std::vector<std::reference_wrapper<const Serializable>> buildings_wrapped(buildings.begin(), buildings.end());
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", buildings_wrapped);
        serializer->Footer("building_repository");

    }

    //2. Functions:

    void XmlSerializer::Header(const std::string &object_name){
        (*output) << "<" <<object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name){
        (*output) << "<\\" <<object_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*output) << "<" << field_name << ">" <<value<< "<\\" << field_name << ">";
    }


    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        (*output) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        (*output) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        (*output) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        XmlSerializer serializer(output);
        value.Serialize(&serializer);
    }


    void XmlSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value) {
        this->Header(field_name);
        for ( const Serializable& element : value) {
            element.Serialize(this);
        }
        this->Footer(field_name);
    }


}