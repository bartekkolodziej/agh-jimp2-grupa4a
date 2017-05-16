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
#include <sstream>

namespace academia {

    class Serializable;

    class Serializer {
    public:
        Serializer(){};
        Serializer(std::ostream *out){};

        virtual  ~Serializer(){};

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

        JsonSerializer(std::stringstream* out){
            this->output = out;
        }

        void IntegerField(const std::string &field_name, int value);

        void DoubleField(const std::string &field_name, double value);

        void StringField(const std::string &field_name, const std::string &value);

        void BooleanField(const std::string &field_name, bool value);

        void SerializableField(const std::string &field_name, const Serializable &value);

        void ArrayField(const std::string &field_name,const std::vector <std::reference_wrapper<const Serializable>> &value);

        //void Header()= 0;

        //void Footer()= 0;

        ~JsonSerializer(){};

        std::stringstream* output;
    };
    
    class XmlSerializer{
    public:
        XmlSerializer(std::stringstream* out){
            this->output = out;
        }

        void IntegerField(const std::string &field_name, int value);

        void DoubleField(const std::string &field_name, double value);

        void StringField(const std::string &field_name, const std::string &value);

        void BooleanField(const std::string &field_name, bool value);

        void SerializableField(const std::string &field_name, const Serializable &value);

        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value);

        void Header(const std::string &object_name);

        void Footer(const std::string &object_name);

        ~XmlSerializer(){};


        std::stringstream* output;
    };

    class MockSerializer : public Serializer{
    public:

        MockSerializer(std::stringstream* out){
            this->output = out;
        }
        MockSerializer(){};
        ~MockSerializer(){};

        void IntegerField(const std::string &field_name, int value){};

        void DoubleField(const std::string &field_name, double value){};

        void StringField(const std::string &field_name, const std::string &value){};

        void BooleanField(const std::string &field_name, bool value){};

        void SerializableField(const std::string &field_name, const Serializable &value){};

        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value){};

        void Header(const std::string &object_name){};

        void Footer(const std::string &object_name){};

        std::stringstream* output;

    };

    class Room : public Serializable{
    public:

        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        std::string Typ(Type type) const {
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
            serializer->IntegerField("id: ", id);
            serializer->StringField("name: ",name);
            serializer->StringField("type: ", Typ(type));
            serializer->Footer("Room");
        };

        void Serialize(JsonSerializer* serializer)const;
        void Serialize(XmlSerializer* serializer)const;

        ~Room(){};
    };

    class Building : public Serializable {
    public:
        std::string name;
        int id;
        std::vector<Room> rooms;

        void Serialize(Serializer* serializer) const  {};
        void Serialize(JsonSerializer* serializer) const;
        void Serialize(XmlSerializer* serializer) const;
        
        Building(int id, std::string name, std::vector<Room> rooms);
        Building(){};
        ~Building(){};
    };

    class BuildingRepository{
    public:

        BuildingRepository( std::initializer_list<Building> buildings){};
        BuildingRepository(){};

        void Add(const Building &building);

        void StoreAll(JsonSerializer* serializer)const;
        void StoreAll(XmlSerializer* serializer)const;
        void StoreAll(MockSerializer* serializer)const;

    //    std::experimental::optional<Building> operator[](int id){};

        std::vector<std::reference_wrapper<const Serializable>> buildings;

        ~BuildingRepository(){};
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H
