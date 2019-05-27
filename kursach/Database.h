#pragma once

#include <string>

#using <System.Data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

ref class Database
{
	String^ connectionString = "Data Source=.\\SQLEXPRESS;Initial Catalog=stas_grischenko;Integrated Security=True";

	DataSet^ loadData(String^ query, String^ tableName);	// загрузит данные по запросу
	Object^ loadValue(String^ query);						// загрузит определённое значение

public:
	DataSet^ loadFlights();							// загрузит всю таблицу Flights
	DataSet^ loadPassager();						// загрузит всю таблицу Passagers
	DataSet^ loadAirportPlanes();					// загрузит всю таблицу AirportPlanes
	DataSet^ loadDescSortedAirportPlanes();			// загрузит отсортированные в обратном порядке самолёты
	DataSet^ loadGroups();							// загрузит все группы пассажиров
	DataSet^ loadGroup(int arr_city);				// загрузит всех пассажиров с определённым городом посадки
	Decimal	 loadGroupBaggageWeight(int arr_city);	// загрузит обший вес багажа группы
	DataSet^ loadCities();							// загрузит всю таблицу Cities
	DataSet^ loadPlanes();							// загрузит всю таблицу Planes
	Decimal  loadCityCost(int id);					// загрузит стоимость перелёта в город
	int loadLastDistGroupId();						// загрузит id последней распределённой группы
	void executeQuery(String^ query);				// выполнит переданный запрос
	void insertIntoDistGroups(int arr_city, int passagers_count, Decimal baggage_weight);	// добавит новую запись в таблицу DistributedPassagersGroups
	void insertIntoPassagers(int arr_city, Decimal baggage_weight);							// добавит новую запись в таблицу Passagers
	void insertIntoFlights(int plane_id, int dist_group_id, int arr_city);					// добавит новую запись в таблицу Flights
	void insertIntoPlanes(String^ title, int capacity, Decimal baggage_capacity);			// добавит новую запись в таблицу Planes
	void insertIntoAirportPlanes(int plane_id, int planes_count);							// добавит новую запись в таблицу AirportPlanes
	void deleteGroup(int arr_city_id, int count);											// удалит определённое кол-во пассажиров, которые летят в определённый город
	void deleteAirportPlanes(int plane_id, int count);										// удалит определённое кол-во самолётов
};