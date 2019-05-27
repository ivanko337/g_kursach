#include "Database.h"

using namespace System;
using namespace System::Collections::Generic;

DataSet^ Database::loadData(String^ query, String^ tableName)
{
	DataSet^ res = gcnew DataSet();
	SqlConnection^ connection;

	try
	{
		connection = gcnew SqlConnection(connectionString);
		connection->Open();
		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
		adapter->FillSchema(res, SchemaType::Source);
		adapter->Fill(res, tableName);
		connection->Close();
	}
	catch (System::Exception^ ex)
	{
		if (connection->State == ConnectionState::Open)
		{
			connection->Close();
		}
		throw ex;
	}

	return res;
}

Object^ Database::loadValue(String^ query)
{
	Object^ res;
	SqlConnection^ connection;
	
	try
	{
		connection = gcnew SqlConnection(connectionString);
		connection->Open();
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		res = command->ExecuteScalar();
		connection->Close();
	}
	catch (System::Exception^ ex)
	{
		if (connection->State == ConnectionState::Open)
		{
			connection->Close();
		}
	}

	return res;
}

DataSet^ Database::loadFlights()
{
	String^ query("SELECT Cities.city_name, Cities.country_name, Planes.title, Planes.capacity, DistributedPassagersGroups.passagers_count, Planes.baggage_capacity, DistributedPassagersGroups.baggage_weight, Cities.cost FROM " +
		"Flights JOIN Cities ON(Cities.id = Flights.arrival_city) JOIN Planes ON(Planes.id = Flights.plane_id) JOIN DistributedPassagersGroups ON(DistributedPassagersGroups.id = Flights.distributed_group_id)");
	String^ tableName("Flights");
	
	return loadData(query, tableName);
}

DataSet^ Database::loadAirportPlanes()
{
	String^ query("SELECT plane_id, Planes.title, planes_count FROM AirportPlanes JOIN Planes ON (AirportPlanes.plane_id = Planes.id)");
	String^ tableName("AirportPlanes");

	return loadData(query, tableName);
}

DataSet^ Database::loadDescSortedAirportPlanes()
{
	String^ query("SELECT plane_id, Planes.title, Planes.baggage_capacity, Planes.capacity, planes_count FROM AirportPlanes JOIN Planes ON (AirportPlanes.plane_id = Planes.id) ORDER BY Planes.capacity");
	String^ tableName("AirportPlanes");

	return loadData(query, tableName);
}

DataSet^ Database::loadPassager()
{
	String^ query("SELECT passagers_count, baggage_weight, Cities.city_name, is_distributed FROM PassagersGroups JOIN Cities ON (PassagersGroups.arrival_city = Cities.id)");
	String^ tableName("PassagersGroups");

	return loadData(query, tableName);
}

DataSet^ Database::loadGroup(int arr_city)
{
	String^ query("SELECT Cities.city_name, baggage_weight FROM Passagers JOIN Cities ON (Cities.id = Passagers.arrival_city) WHERE arrival_city = " + Convert::ToString(arr_city));
	String^ tableName("Passagers");

	return loadData(query, tableName);
}

Decimal Database::loadGroupBaggageWeight(int arr_city)
{
	String^ query("SELECT SUM(baggage_weight) FROM Passagers WHERE arrival_city = " + Convert::ToString(arr_city));

	return Convert::ToDecimal(loadValue(query));
}

DataSet^ Database::loadGroups()
{
	String^ query("SELECT DISTINCT arrival_city FROM Passagers");
	String^ tableName("Passagers");

	DataSet^ uniqueCityValues = loadData(query, tableName);
	List<int>^ cities = gcnew List<int>();
	DataSet^ res = gcnew DataSet();

	for (int i = 0; i < uniqueCityValues->Tables[tableName]->Rows->Count; ++i)
	{
		DataRow^ currRow = uniqueCityValues->Tables[tableName]->Rows[i];
		cities->Add(Convert::ToInt32(currRow["arrival_city"]));
	}

	res->Tables->Add(gcnew String("Groups"));

	res->Tables[gcnew String("Groups")]->Columns->Add(gcnew String("city_name"));
	res->Tables[gcnew String("Groups")]->Columns->Add(gcnew String("arrival_city"));
	res->Tables[gcnew String("Groups")]->Columns->Add(gcnew String("passagers_count"));
	res->Tables[gcnew String("Groups")]->Columns->Add(gcnew String("baggage_weight"));

	for (int i = 0; i < cities->Count; ++i)
	{
		int arr_city = cities[i];

		String^ baggage_query("SELECT SUM(baggage_weight) FROM Passagers WHERE arrival_city = " + Convert::ToString(arr_city));
		String^ count_query("SELECT COUNT(*) FROM Passagers WHERE arrival_city = " + Convert::ToString(arr_city));

		Decimal baggage_weight = Convert::ToDecimal(loadValue(baggage_query));
		int count = Convert::ToInt32(loadValue(count_query));

		DataRow^ row = res->Tables[gcnew String("Groups")]->NewRow();

		row[gcnew String("arrival_city")] = arr_city;
		row[gcnew String("passagers_count")] = count;
		row[gcnew String("baggage_weight")] = baggage_weight;

		res->Tables[gcnew String("Groups")]->Rows->Add(row);
	}

	for (int i = 0; i < res->Tables[gcnew String("Groups")]->Rows->Count; ++i)
	{
		DataRow^ row = res->Tables[gcnew String("Groups")]->Rows[i];
		int arr_city = Convert::ToInt32(row[gcnew String("arrival_city")]);
		String^ query("SELECT city_name FROM Cities WHERE id = " + Convert::ToString(arr_city));
		String^ name = Convert::ToString(loadValue(query));
		row[gcnew String("city_name")] = name;
	}

	return res;
}

DataSet^ Database::loadCities()
{
	String^ query("SELECT id, city_name, cost FROM Cities");
	String^ tableName("Cities");

	return loadData(query, tableName);
}

DataSet^ Database::loadPlanes()
{
	String^ query("SELECT id, title FROM Planes");
	String^ tableName("Planes");

	return loadData(query, tableName);
}

Decimal Database::loadCityCost(int id)
{
	String^ query("SELECT cost FROM Cities WHERE id = " + Convert::ToString(id));

	return Convert::ToInt32(loadValue(query));
}

void Database::executeQuery(String^ query)
{
	SqlConnection^ connection;
	try
	{
		connection = gcnew SqlConnection(connectionString);
		connection->Open();
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		command->ExecuteNonQuery();
		connection->Close();
	}
	catch(System::Exception^ ex)
	{
		if (connection->State == ConnectionState::Open)
		{
			connection->Close();
		}
		throw ex;
	}
}

int Database::loadLastDistGroupId()
{
	String^ query("SELECT TOP 1 id FROM DistributedPassagersGroups ORDER BY id DESC");

	return Convert::ToInt32(loadValue(query));
}

void Database::insertIntoDistGroups(int arr_city, int passagers_count, Decimal baggage_weight)
{
	String^ query("INSERT INTO DistributedPassagersGroups(arrival_city, passagers_count, baggage_weight) " +
		"VALUES (:arrival_city, :passagers_count, :baggage_weight)");
	query = query->Replace(":arrival_city", System::Convert::ToString(arr_city));
	query = query->Replace(":passagers_count", System::Convert::ToString(passagers_count));
	query = query->Replace(":baggage_weight", System::Convert::ToString(baggage_weight)->Replace(",", "."));
	executeQuery(query);
}

void Database::insertIntoPassagers(int arr_city, Decimal baggage_weight)
{
	String^ query("INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (:arrival_city, :baggage_weight)");
	query = query->Replace(":arrival_city", Convert::ToString(arr_city));
	query = query->Replace(":baggage_weight", Convert::ToString(baggage_weight));
	executeQuery(query);
}

void Database::insertIntoFlights(int plane_id, int dist_group_id, int arr_city)
{
	String^ query("INSERT INTO Flights(plane_id, distributed_group_id, arrival_city)" +
		"VALUES(:plane_id, :distributed_group_id, :arrival_city)");
	query = query->Replace(":plane_id", Convert::ToString(plane_id));
	query = query->Replace(":distributed_group_id", Convert::ToString(dist_group_id));
	query = query->Replace(":arrival_city", Convert::ToString(arr_city));
	executeQuery(query);
}

void Database::insertIntoPlanes(String^ title, int capacity, Decimal baggage_capacity)
{
	String^ query("INSERT INTO Planes(title, capacity, baggage_capacity)" +
		"VALUES (':title', :capacity, :baggage_capacity)");
	query = query->Replace(":title", title);
	query = query->Replace(":capacity", Convert::ToString(capacity));
	query = query->Replace(":baggage_capacity", Convert::ToString(baggage_capacity));
	executeQuery(query);
}

void Database::insertIntoAirportPlanes(int plane_id, int planes_count)
{
	String^ allPlanesQuery("SELECT DISTINCT plane_id FROM AirportPlanes");

	DataTable^ allPlanes = loadData(allPlanesQuery, "AirportPlanes")->Tables["AirportPlanes"];
	int planesCount = allPlanes->Select("plane_id = " + Convert::ToString(plane_id))->Length;
	String^ query;

	if (planesCount == 0)
	{
		query = "INSERT INTO AirportPlanes(plane_id, planes_count) " +
			"VALUES (:plane_id, :planes_count)";
		query = query->Replace(":plane_id", Convert::ToString(plane_id));
		query = query->Replace(":planes_count", Convert::ToString(planes_count));
	}
	else
	{
		query = "UPDATE AirportPlanes SET planes_count += " + Convert::ToString(planes_count) + " WHERE plane_id = " + Convert::ToString(plane_id);
	}

	executeQuery(query);
}

void Database::deleteGroup(int arr_city_id, int count)
{
	String^ subQuery("SELECT TOP " + Convert::ToString(count) + " id FROM Passagers WHERE arrival_city = " + Convert::ToString(arr_city_id));
	String^ query("DELETE FROM Passagers WHERE id IN (" + subQuery + ")");

	executeQuery(query);
}

void Database::deleteAirportPlanes(int plane_id, int count)
{
	DataSet^ planes = loadData("SELECT * FROM AirportPlanes WHERE plane_id = " + Convert::ToString(plane_id), "AirportPlanes");
	DataRow^ currRow = planes->Tables["AirportPlanes"]->Rows[0];
	String^ query;
	int planes_count = Convert::ToInt32(currRow["planes_count"]);

	if (planes_count - count == 0)
	{
		query = "DELETE FROM AirportPlanes WHERE plane_id = " + Convert::ToString(plane_id);
	}
	else
	{
		query = "UPDATE AirportPlanes SET planes_count -= " + Convert::ToString(count) + " WHERE plane_id = " + Convert::ToString(plane_id);
	}

	executeQuery(query);
}