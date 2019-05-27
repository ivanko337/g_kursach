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

	DataSet^ loadData(String^ query, String^ tableName);	// �������� ������ �� �������
	Object^ loadValue(String^ query);						// �������� ����������� ��������

public:
	DataSet^ loadFlights();							// �������� ��� ������� Flights
	DataSet^ loadPassager();						// �������� ��� ������� Passagers
	DataSet^ loadAirportPlanes();					// �������� ��� ������� AirportPlanes
	DataSet^ loadDescSortedAirportPlanes();			// �������� ��������������� � �������� ������� �������
	DataSet^ loadGroups();							// �������� ��� ������ ����������
	DataSet^ loadGroup(int arr_city);				// �������� ���� ���������� � ����������� ������� �������
	Decimal	 loadGroupBaggageWeight(int arr_city);	// �������� ����� ��� ������ ������
	DataSet^ loadCities();							// �������� ��� ������� Cities
	DataSet^ loadPlanes();							// �������� ��� ������� Planes
	Decimal  loadCityCost(int id);					// �������� ��������� ������� � �����
	int loadLastDistGroupId();						// �������� id ��������� ������������� ������
	void executeQuery(String^ query);				// �������� ���������� ������
	void insertIntoDistGroups(int arr_city, int passagers_count, Decimal baggage_weight);	// ������� ����� ������ � ������� DistributedPassagersGroups
	void insertIntoPassagers(int arr_city, Decimal baggage_weight);							// ������� ����� ������ � ������� Passagers
	void insertIntoFlights(int plane_id, int dist_group_id, int arr_city);					// ������� ����� ������ � ������� Flights
	void insertIntoPlanes(String^ title, int capacity, Decimal baggage_capacity);			// ������� ����� ������ � ������� Planes
	void insertIntoAirportPlanes(int plane_id, int planes_count);							// ������� ����� ������ � ������� AirportPlanes
	void deleteGroup(int arr_city_id, int count);											// ������ ����������� ���-�� ����������, ������� ����� � ����������� �����
	void deleteAirportPlanes(int plane_id, int count);										// ������ ����������� ���-�� ��������
};