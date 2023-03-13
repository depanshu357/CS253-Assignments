#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

class newDate
{
public:
    int day, month, year;
    newDate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void printDate()
    {
        cout << day << "/" << month << "/" << year;
    }
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

int countLeapYears(newDate *d)
{
    int years = d->year;
    if (d->month <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}
int getDifference(newDate *dt1, newDate *dt2)
{
    long int n1 = dt1->year * 365 + dt1->day;
    for (int i = 0; i < dt1->month - 1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(dt1);
    long int n2 = dt2->year * 365 + dt2->day;
    for (int i = 0; i < dt2->month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}

// Planets
class Planet
{
public:
    int Position_X, Position_Y, Position_Z;
    string PlanetName;
    void getCoordinate()
    {
        cout << "X = " << Position_X << " Y = " << Position_Y << " Z = " << Position_Z << endl;
    }
    Planet(int X, int Y, int Z, string PlanetName)
    {
        Position_X = X;
        Position_Y = Y;
        Position_Z = Z;
        this->PlanetName = PlanetName;
    }
    int getX() { return Position_X; }
    int getY() { return Position_Y; }
    int getZ() { return Position_Z; }
    string getPlanetName() { return PlanetName; }

    void updateX(int X) { Position_X = X; }
    void updateY(int Y) { Position_Y = Y; }
    void updateZ(int Z) { Position_Z = Z; }
    void updatePlanetName(string PlanetName) { this->PlanetName = PlanetName; }
};

class Moon : public Planet
{
public:
    string Atmosphere = "Has no atmosphere";
    string Water = "Has water on poles";

    void getAtmoshphereInfo() { cout << Atmosphere << endl; }
    void getWaterInfo() { cout << Water << endl; }

    void updateAtmosphereInfo(string Atmosphere) { this->Atmosphere = Atmosphere; }
    void updateWaterInfo(string Water) { this->Water = Water; }

    Moon(int X, int Y, int Z, string PlanetName)
        : Planet(X, Y, Z, PlanetName) {}
};

class Mars : public Planet
{
public:
    string Atmosphere = "Has great variations in temperatures";
    string Water = "No sources of water present";
    string inhabitants;

    string getAtmosphereInfo() { return Atmosphere; }
    string getWaterInfo() { return Water; }
    string getInhabitantsInfo() { return inhabitants; }

    void updateAtmosphereInfo(string Atmosphere) { this->Atmosphere = Atmosphere; }
    void updateWaterInfo(string Water) { this->Water = Water; }
    void updateInhabitantsInfo(string inhabitants) { this->inhabitants = inhabitants; }

    Mars(int X, int Y, int Z, string PlanetName)
        : Planet(X, Y, Z, PlanetName) {}
};

class Pandora : public Planet
{
public:
    string Atmosphere = "Can live without oxygen for 3min max";
    string Water = "Present";
    string inhabitants = "Avatars";
    string wildlife = "Six legged mammals are common";

    string getAtmosphereInfo() { return Atmosphere; }
    string getWaterInfo() { return Water; }
    string getInhabitants() { return inhabitants; }
    string getWildlifeInfo() { return wildlife; }

    void updateAtmosphereInfo(string Atmosphere) { this->Atmosphere = Atmosphere; }
    void updateWaterInfo(string Water) { this->Water = Water; }
    void updateInhabitantsInfo(string inhabitants) { this->inhabitants = inhabitants; }
    void updateWildlifeInfo(string wildlife) { this->wildlife = wildlife; }

    Pandora(int X, int Y, int Z, string PlanetName)
        : Planet(X, Y, Z, PlanetName) {}
};

// Tickets

class Ticket
{
private:
    int Price;

public:
    Planet *SourceStation;
    Planet *DestinationStation;
    newDate *Date;
    string TravellerName;
    string ID;
    // Traveller* newTraveller;
    void bookTicket(Planet *SourceStation, Planet *DestinationStation, newDate *Date)
    {
        this->SourceStation = SourceStation;
        this->DestinationStation = DestinationStation;
        this->Date = Date;
    }

    newDate *getDate() { return Date; }
    Planet *getSourceStation() { return SourceStation; }
    Planet *getDestinationStation() { return DestinationStation; }
    string getTravellerName() { return TravellerName; }
    // Traveller* getTraveller(){return newTraveller;}
    string getID() { return ID; }

    void updateDate(newDate *Date) { this->Date = Date; }
    void updateSourceStation(Planet *SourceStation) { this->SourceStation = SourceStation; }
    void updateDestinationStation(Planet *DestinationStation) { this->DestinationStation = DestinationStation; }
    void updateTravellerName(string TravellerName) { this->TravellerName = TravellerName; }
    void updateID(string ID) { this->ID = ID; }

    long long price()
    {
        long long diffX1 = (SourceStation->getX());
        long long diffY1 = (SourceStation->getY());
        long long diffZ1 = (SourceStation->getZ());
        long long diffX2 = (DestinationStation->getX());
        long long diffY2 = (DestinationStation->getY());
        long long diffZ2 = (DestinationStation->getZ());

        long long constantK = sqrt((diffX1 - diffX2) * (diffX1 - diffX2) + (diffY1 - diffY2) * (diffY1 - diffY2) + (diffZ1 - diffZ2) * (diffZ1 - diffZ2)) * 1000;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        newDate presentDate = newDate(ltm->tm_mday, ltm->tm_mon, 1900 + ltm->tm_year);
        long long noOfDays = getDifference(&presentDate, Date);
        // cout <<" d "<<noOfDays << " k "<<endl;
        return (constantK / (noOfDays + 1));
    }
    long long getPrice()
    {
        return price();
    }
    void printTicket()
    {
        cout << "\nTravller Name - " << getTravellerName();
        cout << "\nTraveller ID - " << getID();
        cout << "\nSourceStation - " << getSourceStation()->getPlanetName();
        cout << "\nDestinationStation - " << getDestinationStation()->getPlanetName();
        cout << "\nDate - " << getDate()->day << "/" << getDate()->month << "/" << getDate()->year;
    }
};

class Traveller
{
private:
    string Traveller_id;

public:
    string Name, ID;
    vector<Ticket *> list_of_person_tickets;
    static vector<Ticket *> list_of_all_tickets;
    Traveller(string Name, string ID, string Traveller_id)
    {
        this->Name = Name;
        this->ID = ID;
        this->Traveller_id = Traveller_id;
    }
    string getName() { return Name; }
    string getId() { return ID; }
    void verifyId(string ID)
    {
        if (this->ID == ID)
        {
            cout << "Verified\n";
        }
        else
            cout << "Not Verified\n";
    }
    void update_ID(string ID) { this->ID = ID; }
    void updateName(string Name) { this->Name = Name; }
    void updateId(string ID) { this->ID = ID; }

    static void addToListOfAllTickets(Ticket *ticket)
    {
        list_of_all_tickets.push_back(ticket);
    }

    static void printAllTickets()
    {
        int n = list_of_all_tickets.size();
        for (int i = 0; i < n; i++)
        {
            list_of_all_tickets[i]->printTicket();
        }
    }

    Ticket *makeNewTicket(Planet *SourceStation, Planet *DestinationStation, newDate *Date)
    {
        Ticket *newTicket = new Ticket();
        newTicket->SourceStation = SourceStation;
        newTicket->DestinationStation = DestinationStation;
        newTicket->Date = Date;
        newTicket->ID = ID;
        newTicket->TravellerName = Name;
        // newTicket->newTraveller = this;
        list_of_person_tickets.push_back(newTicket);
        addToListOfAllTickets(newTicket);
        cout << "New Ticket from " + SourceStation->PlanetName + " to " + DestinationStation->PlanetName + " added for " + Name << endl;
        return newTicket;
    }
    Ticket *updateTicketSourceStation(int index, Planet *newSourceStation)
    {
        list_of_person_tickets[index - 1]->SourceStation = newSourceStation;
        return list_of_person_tickets[index - 1];
    }
    Ticket *updateTicketDestinationStation(int index, Planet *newDestinationStation)
    {
        list_of_person_tickets[index - 1]->DestinationStation = newDestinationStation;
        return list_of_person_tickets[index - 1];
    }
    Ticket *updateTicketDate(int index, newDate *Date)
    {
        list_of_person_tickets[index - 1]->Date = Date;
        return list_of_person_tickets[index - 1];
    }
    Ticket *updateTicket(int index, Ticket *updatedTicket)
    {
        list_of_person_tickets[index - 1] = updatedTicket;
        return list_of_person_tickets[index - 1];
    }
    void deleteTicket(int index)
    {
        for (int i = 0; i < list_of_all_tickets.size(); i++)
        {
            if (list_of_all_tickets[i] == list_of_person_tickets[index - 1])
            {
                list_of_all_tickets.erase(list_of_all_tickets.begin() + i);
                break;
            }
        }
        delete list_of_person_tickets[index - 1];

        list_of_person_tickets.erase(list_of_person_tickets.begin() + index - 1);
        cout << "\nDelelted successfully";
    }
    void get_all_tickets()
    {
        for (int i = 0; i < list_of_person_tickets.size(); i++)
        {
            cout << "TicketNo - " << i + 1;
            cout << "\nTraveller Name -  " << getName();
            cout << "\nSourceStation - " << list_of_person_tickets[i]->getSourceStation()->getPlanetName();
            cout << "\nDestinationStation - " << list_of_person_tickets[i]->getDestinationStation()->getPlanetName();
            cout << "\nPrice - " << list_of_person_tickets[i]->getPrice();
            cout << "\nDate - ";
            (list_of_person_tickets[i]->getDate())->printDate();
        }
    }
};

class Astronaut : public Traveller
{
private:
    int experience;
    string flyingLicense;
    string LicenseID;

public:
    static vector<Astronaut *> list_of_all_astronauts;
    void addToListOfAstronauts()
    {
        list_of_all_astronauts.push_back(this);
    }
    Astronaut(string Name, string ID, string Traveller_id, int experience)
        : Traveller(Name, ID, Traveller_id)
    {
        this->experience = experience;
        addToListOfAstronauts();
    }
    string getFlyingLicencse() { return flyingLicense; }
    string getLicenseID() { return LicenseID; }
    int getExperience() { return experience; }

    void updateFlyingLicense(string newFlyingLicense) { flyingLicense = newFlyingLicense; }
    void updateLicenseID(string newLicenseID) { LicenseID = newLicenseID; }
    void updateExperience(int newExperience) { experience = newExperience; }
};
class Passenger : public Traveller
{
private:
    int validity = 10 * 365 + 2;

public:
    void getValidity() { cout << validity << endl; }

    void updateValidity() { this->validity = validity; }

    Passenger(string Name, string ID, string Traveller_id)
        : Traveller(Name, ID, Traveller_id)
    {
    }
};
class Commander : public Traveller
{
private:
    string Authority;
    string LicencseID;

public:
    int experience;
    static vector<Commander *> list_of_commanders;

    void getAuthority() { cout << Authority << endl; }
    void getLicencseID() { cout << LicencseID << endl; }
    void getExperience() { cout << experience << endl; }

    void updateAuthority(string Authority) { this->Authority = Authority; }
    void updateLicencseID(string LicencseID) { this->LicencseID = LicencseID; }
    void updateExperiece(int experience) { this->experience = experience; }

    void addCommanderID(string ID)
    {
        list_of_commanders.push_back(this);
    }

    Commander(string Name, string ID, string Traveller_id, int experience, string LicencseID, string Authority)
        : Traveller(Name, ID, Traveller_id)
    {
        this->Authority = Authority;
        this->LicencseID = LicencseID;
        this->experience = experience;
        addCommanderID(ID);
        // (this->list_of_commanders).push_back(ID);
    }
};

class SpaceTravel
{
private:
    Planet *SourceStation;
    Planet *DestinationStation;

public:
    vector<Traveller *> Travellers;
    Astronaut *newAstronaut;
    Commander *newCommander;
    vector<Ticket *> Tickets;
    void addTraveller(Traveller *newTraveller)
    {
        Travellers.push_back(newTraveller);
    };
    void printListOfTravellers()
    {
        for (int i = 0; i < Travellers.size(); i++)
        {
            cout << Travellers[i]->getName() << " " << Travellers[i]->getId() << endl;
        }
    }
    Astronaut *getAstronaut()
    {
        return newAstronaut;
    }
    Commander *getCommander()
    {
        return newCommander;
    }
    void setAstronaut(Astronaut *newAstronaut)
    {
        this->newAstronaut = newAstronaut;
    }
    void setCommander(Commander *newCommander)
    {
        this->newCommander = newCommander;
    }
    void updateAstronautId(string ID)
    {
        this->newAstronaut->ID = ID;
    }
    void updateCommanderID(string ID)
    {
        this->newCommander->ID = ID;
    }
    void changeCommanderID(Commander *newCommander)
    {
        this->newCommander = newCommander;
    }
    void printTickets()
    {
        for (int i = 0; i < Tickets.size(); i++)
        {
            Tickets[i]->printTicket();
            // Travellers.push_back(Tickets[i]->newTraveller);
        }
    }
};

SpaceTravel *SpaceTravelObject(vector<Ticket *> list_of_all_tickets, Commander *newCommander, Astronaut *newAstronaut)
{
    SpaceTravel *SpaceTravelObject = new SpaceTravel();
    int n = list_of_all_tickets.size();
    for (int i = 0; i < n; i++)
    {
        // if(aTicket->getDate() == list_of_all_tickets[i]->getDate() ){
        (SpaceTravelObject->Tickets).push_back(list_of_all_tickets[i]);
        // }
    }
    if ((SpaceTravelObject->Tickets).size() <= 2)
    {
        cout << "Not enough travellers, flight cancelled.";
        return NULL;
    }
    SpaceTravelObject->setCommander(newCommander);
    SpaceTravelObject->setAstronaut(newAstronaut);
    cout << "Tickets booked for passengers with Commander " + newCommander->getName() + " and Astronaut " + newAstronaut->getName();
    return SpaceTravelObject;
}

vector<SpaceTravel *> makeSpaceTravelObjects(vector<Ticket *> list_of_all_tickets, vector<Commander *> list_of_commanders, vector<Astronaut *> list_of_astronauts)
{
    int n = list_of_all_tickets.size();
    vector<SpaceTravel *> verifiedSpaceTravelObjects;
    map<string, vector<Ticket *>> mpSpaceTravel;
    for (int i = 0; i < n; i++)
    {
        string uniqueCode = list_of_all_tickets[i]->SourceStation->getPlanetName() +
                            list_of_all_tickets[i]->DestinationStation->getPlanetName() +
                            to_string(list_of_all_tickets[i]->Date->day) + to_string(list_of_all_tickets[i]->Date->month) +
                            to_string(list_of_all_tickets[i]->Date->year);
        if (mpSpaceTravel.find(uniqueCode) != mpSpaceTravel.end() && mpSpaceTravel[uniqueCode].size() == 10)
            continue;
        mpSpaceTravel[uniqueCode].push_back(list_of_all_tickets[i]);
    }
    int j = 0;
    for (auto it = mpSpaceTravel.begin(); it != mpSpaceTravel.end() && j < list_of_astronauts.size() && j < list_of_commanders.size(); it++, j++)
    {
        if (it->second.size() > 2)
        {
            verifiedSpaceTravelObjects.push_back(SpaceTravelObject(it->second, list_of_commanders[j], list_of_astronauts[j]));
        }
    }
    return verifiedSpaceTravelObjects;
}

void printSpaceTravelObjects(vector<SpaceTravel *> SpaceTravelObject)
{
    for (int i = 0; i < SpaceTravelObject.size(); i++)
    {
        cout << "\n-------------------\n";
        cout << "Commander - " << SpaceTravelObject[i]->getCommander()->getName() << endl;
        cout << "Astronaut - " << SpaceTravelObject[i]->getAstronaut()->getName() << endl;
        SpaceTravelObject[i]->printTickets();
        cout << "\n-------------------\n";
    }
}

vector<Ticket *> Traveller::list_of_all_tickets;
vector<Commander *> Commander::list_of_commanders;
vector<Astronaut *> Astronaut::list_of_all_astronauts;

int main()
{
    Moon Moon1 = Moon(20, 34, 14, "MoonOfEarth");
    Moon1.updateAtmosphereInfo("No Atmoshphere");
    Moon1.updateWaterInfo("Water is present at the poles");
    Mars Mars1 = Mars(123, 245, 64, "Mars");
    Mars1.updateAtmosphereInfo("Extreme Atmoshpheres");
    Mars1.updateInhabitantsInfo("Microscopic life may be present");
    Planet Venus = Planet(1234, 523, 190, "Venus");
    Pandora Pandora1 = Pandora(23455, 6466, 6546, "Pandora");
    Pandora1.updateAtmosphereInfo("Can live withour oxygen for maximum 3 minutes");
    Pandora1.updateWaterInfo("Water is present in huge amounts");
    Pandora1.updateInhabitantsInfo("Avatars are present");
    Pandora1.updateWildlifeInfo("Six legged mammals are found");

    Planet *Planet1 = &Moon1;
    Planet *Planet2 = &Mars1;
    Planet *Planet3 = &Venus;
    Planet *Planet4 = &Pandora1;

    Astronaut Astronaut1 = Astronaut("Abhinav", "2!23", "1343", 23);
    Astronaut Astronaut2 = Astronaut("Manpreet", "2!13", "1243", 20);

    Commander Commander1 = Commander("Vivek", "1343", "2341", 23, "4123", "Supreme");
    Commander Commander2 = Commander("Virat", "1443", "6341", 23, "3123", "Assistant");

    Passenger Passenger1 = Passenger("Elon", "1234", "A23$");
    Passenger Soham = Passenger("Soham", "210214", "ASd12");
    Passenger Rohan = Passenger("Rohan", "210456", "AS213");
    Passenger Shubham = Passenger("Shubham", "210345", "AS345");
    Passenger Hermione = Passenger("Hermione", "210436", "ASD436");
    Passenger Ron = Passenger("Ron", "210129", "ASD129");
    Passenger Robin = Passenger("Robin", "210678", "ASD678");
    Passenger Palak = Passenger("Palak", "210378", "ASD378");
    Passenger Abhishek = Passenger("Abhishek", "3234", "325254");

    newDate Date1 = newDate(3, 5, 2024);
    newDate Date2 = newDate(21, 8, 2024);
    newDate Date3 = newDate(21, 3, 2024);

    // string Name;
    // cin>>Name;
    cout << Passenger1.getName() << endl;
    Passenger1.updateName("Elon Musk");
    cout << Passenger1.getName() << endl;
    cout << Astronaut1.getName() << endl;
    cout << Astronaut1.ID << endl;

    Ticket *Ticket1 = Passenger1.makeNewTicket(Planet1, Planet2, &Date1);
    Ticket *Ticket3 = Palak.makeNewTicket(Planet2, Planet3, &Date3);
    Ticket *Ticket2 = Soham.makeNewTicket(Planet2, Planet1, &Date2);
    Ticket *Ticket4 = Passenger1.makeNewTicket(Planet2, Planet1, &Date2);
    Ticket *Ticket5 = Hermione.makeNewTicket(Planet2, Planet1, &Date2);
    Ticket *Ticket6 = Abhishek.makeNewTicket(Planet2, Planet1, &Date2);
    Ticket *Ticket7 = Robin.makeNewTicket(Planet2, Planet3, &Date3);
    Ticket *Ticket8 = Ron.makeNewTicket(Planet2, Planet3, &Date3);
    // Tickets are made for passengers but they are not booked or reserved for passengers until they are inserted in the space travel class;

    Traveller *Traveller1 = &Passenger1;
    Traveller *Traveller2 = &Hermione;
    Traveller *Traveller3 = &Abhishek;

    // Traveller::addToListOfAllTickets(Ticket6);
    vector<Traveller *> Passengers;
    Passengers.push_back(Traveller1);
    Passengers.push_back(Traveller2);

    cout << Ticket1->getPrice() << endl;
    cout << Ticket2->getPrice() << endl;
    // Passenger1.get_all_tickets();
    cout << Traveller::list_of_all_tickets.size();
    Passenger1.deleteTicket(1);
    cout << Traveller::list_of_all_tickets.size();
    // Passenger1.get_all_tickets();
    vector<SpaceTravel *> SpaceTravelObject1 = makeSpaceTravelObjects(Traveller::list_of_all_tickets, Commander::list_of_commanders, Astronaut::list_of_all_astronauts);
    // no conflit of same commander or astronaut on different spaceTravel objects can arise they are distributed by the algorithm
    // tickets are added in this function as ticket is unique and ticket contains information about the traveller
    printSpaceTravelObjects(SpaceTravelObject1);

    // SpaceTravel* SpaceTravel1 = SpaceTravelObject(Ticket6,Traveller::list_of_all_tickets,&Commander1,&Astronaut1);
    // cout << Traveller::list_of_all_tickets[0];
    // Traveller::printAllTickets();
    // cout<<Commander1.list_of_commanders.size();
    // (Traveller3->list_of_all_travellers).size();
    return 0;
}