#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class RoadObjectClass;
class Person;

/*-----------------------------------------------------------------------------
 * The header to implement your own exceptions for debug.
 * Feel free to add any, just copy the first class and name it with your error
 * type
 * Contact info - Alexey
 *-----------------------------------------------------------------------------*/
class NullPtrException : public std::exception
{
    public:
	virtual const char* what() const noexcept {
		return "Error! A nullptr was accessed!";
	}
    protected:

    private:
};

/*-----------------------------------------------------------------------------
 * An exception if the Navigator returns nullptr as the next road or destination
 *-----------------------------------------------------------------------------*/
class NavigatorException : public std::exception
{
    public:
	NavigatorException( const RoadObjectClass* ptrToErrorObject ) : m_objectPtr{ ptrToErrorObject }
	{
	}

	virtual const char* what() const noexcept {
		return "Error: the navigator has proposed null as the next route";
	}

	const RoadObjectClass* getErrorObject(){
		return m_objectPtr;
	}

    protected:

    private:
	const RoadObjectClass* m_objectPtr;
};

/*-----------------------------------------------------------------------------
 * Sometimes Building::RemovePerson() tries to access nullptr,
 * I hope this helps to find it
 *-----------------------------------------------------------------------------*/
class BuildingRemovePersonException : public std::exception
{
    public:
	BuildingRemovePersonException( const RoadObjectClass* ptrToErrorObject, const Person* ptrToPerson )
		: m_objectPtr{ ptrToErrorObject }, m_personPtr{ ptrToPerson }
	{
	}

	virtual const char* what() const noexcept {
		return "The building tried to access nullptr when removing a person (person's current location or destination was nullptr)";
	}

	const RoadObjectClass* getErrorBuilding(){
		return m_objectPtr;
	}
	const Person* getErrorPerson(){
		return m_personPtr;
	}

    protected:

    private:
	const RoadObjectClass* m_objectPtr;
	const Person* m_personPtr;
};


#endif // EXCEPTIONS_HPP
