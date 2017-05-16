//
// Created by bartek on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <experimental/optional>

namespace academia {

    class Serializable;
    class Room;
    class Building;

    std::vector <std::reference_wrapper<const Serializable>>RoomsToReferenceWrapper(std::vector<Room> array);
    std::vector <std::reference_wrapper<const Serializable>>BuildingsToReferenceWrapper(std::vector<Building> array);

    class Serializer {
    public:
        Serializer(std::ostream *out){};

        virtual ~Serializer()= 0;

        virtual void IntegerField(const std::string &field_name, int value) = 0;

        virtual void DoubleField(const std::string &field_name, double value)= 0;

        virtual void StringField(const std::string &field_name, const std::string &value)= 0;

        virtual void BooleanField(const std::string &field_name, bool value)= 0;

        virtual void SerializableField(const std::string &field_name, const Serializable &value)= 0;

        virtual void ArrayField(const std::string &field_name, const std::vector <std::reference_wrapper<const Serializable>> &value)= 0;

        virtual void Header(const std::string &object_name)= 0;

        virtual void Footer(const std::string &object_name)= 0;
        

    };
    class JsonSerializer;
    class XmlSerializer;
    class Serializable {
    public:
        virtual void Serialize(Serializer* serializer) const = 0;
        virtual void Serialize(JsonSerializer* serializer) const = 0;
        virtual void Serialize(XmlSerializer* serializer) const = 0;

    };
    
    class JsonSerializer{
    public:

        JsonSerializer(std::ostream* out){ std::ostream * output = out; }

        void IntegerField(const std::string &field_name, int value);

        void DoubleField(const std::string &field_name, double value);

        void StringField(const std::string &field_name, const std::string &value);

        void BooleanField(const std::string &field_name, bool value);

        void SerializableField(const std::string &field_name, const Serializable &value);

        void ArrayField(const std::string &field_name,const std::vector <std::reference_wrapper<const Serializable>> &value);

        //void Header()= 0;

        //void Footer()= 0;

        ~JsonSerializer(){};

        std::ostream* output;
    };
    
    class XmlSerializer{
    public:
        XmlSerializer(std::ostream* out){std::ostream * output = out;}

        void IntegerField(const std::string &field_name, int value);

        void DoubleField(const std::string &field_name, double value);

        void StringField(const std::string &field_name, const std::string &value);

        void BooleanField(const std::string &field_name, bool value);

        void SerializableField(const std::string &field_name, const Serializable &value);

        void ArrayField(const std::string &field_name, const std::vector <std::reference_wrapper<const Serializable>> &value);

        void Header(const std::string &object_name);

        void Footer(const std::string &object_name);

        ~XmlSerializer(){};

        std::ostream* output;
    };

    class Room : public Serializable{
    public:

        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        std::string ReturnTypeString(Type type) const {
            switch (type) {
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";
                case Type::LECTURE_HALL:
                    return "LECTURE_HALL";
                case Type::CLASSROOM:
                    return "CLASSROOM";

            }
        }


        Room(int id, std::string name,Type type);
        Room(){};

        std::string name;
        int id;
        Type type;

        void Serialize(Serializer* serializer) const{
            serializer->Header("Room");
            serializer->IntegerField("Id: ", id);
            serializer->StringField("name: ",name);
            serializer->StringField("type: ", ReturnTypeString(type));
            serializer->Footer("Room");
        };

        void Serialize(JsonSerializer* serializer)const;
        void Serialize(XmlSerializer* serializer)const;

        ~Room(){};
    };

    class Building : public Serializable {
    public:
        std::string name;
        int Id;
        std::vector<Room> rooms;
        

        void Serialize(JsonSerializer* serializer) const;
        void Serialize(XmlSerializer* serializer) const;
        void Serialize(Serializer* serializer) const{};
        
        Building(int id, std::string name, std::initializer_list<Room> rooms);
        Building(){};
        ~Building(){};
    };

    class BuildingRepository : public Serializable{
    public:
        BuildingRepository( std::initializer_list<Building> buildings);
        BuildingRepository(){};

        void Add(const Building &building);
        void StoreAll(Serializer* serializer)const{};
        void StoreAll(JsonSerializer* serializer)const;
        void StoreAll(XmlSerializer* serializer)const;

        std::experimental::optional<Building> operator[](int id);

        std::vector<Building> buildings;

        ~BuildingRepository(){};
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H
