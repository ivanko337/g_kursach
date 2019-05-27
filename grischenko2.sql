USE kursach

-- ������� ��� ������� ����� ���������
DROP TABLE IF EXISTS AirportPlanes
DROP TABLE IF EXISTS Flights
DROP TABLE IF EXISTS Planes
DROP TABLE IF EXISTS Passagers
DROP TABLE IF EXISTS DistributedPassagersGroups
DROP TABLE IF EXISTS Cities

CREATE TABLE Cities( -- ������� �������
	id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY,
	city_name VARCHAR(60) NOT NULL, -- �������� ������
	country_name VARCHAR(60) NOT NULL, -- �������� ������, � ������� ���� ����� ���������
	cost DECIMAL(10, 2) NOT NULL -- ��������� ������� � BYN
)

CREATE TABLE Planes( -- ������� ����� ��������
	id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY,
	title VARCHAR(20) NOT NULL, -- �������� �������
	capacity INT NOT NULL, -- ����������� �������
	baggage_capacity DECIMAL(10, 2) NOT NULL -- ����������� ������ � ��
)

CREATE TABLE AirportPlanes( -- ������� ��������, ������� ���� � ������� � ���������
	id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY,
	plane_id INT NOT NULL, -- ��� �������
	planes_count INT NOT NULL, -- ���-�� �������� ������ ����
	FOREIGN KEY(plane_id) REFERENCES Planes(id) -- ��������� �� ������ � ������� ����� ��������
)

CREATE TABLE Passagers( -- ������� ���� ����������
	id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY,
	arrival_city INT NOT NULL, -- ����� � ������� ����� �������
	baggage_weight DECIMAL(10, 2) NOT NULL, -- ��� ��� ������ � ��
	FOREIGN KEY(arrival_city) REFERENCES Cities(id)
)

CREATE TABLE DistributedPassagersGroups( -- ������������� ������ ����������
	id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY, 
	arrival_city INT NOT NULL, -- �����, � ������� ��� �����
	passagers_count INT NOT NULL, -- ���-�� ���������� � ������ ������
	baggage_weight DECIMAL(10, 2) NOT NULL, -- ����� ��� ������ ���� ����������
	FOREIGN KEY(arrival_city) REFERENCES Cities(id)
)

CREATE TABLE Flights( -- ������� ������
	id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY,
	plane_id INT NOT NULL, -- ������
	distributed_group_id INT NOT NULL, -- ������������� ������
	arrival_city INT NOT NULL, -- �����, � ������� �����
	FOREIGN KEY(plane_id) REFERENCES Planes(id),
	FOREIGN KEY(distributed_group_id) REFERENCES DistributedPassagersGroups(id),
	FOREIGN KEY(arrival_city) REFERENCES Cities(id)
)

INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '������', 300)								-- 1
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�����-���������', '������', 300)					-- 2
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '��������', 500)							-- 3
INSERT INTO Cities(city_name, country_name, cost) VALUES ('���-����', '���', 2100)								-- 4
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '��������������', 2100)						-- 5
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������', '������', 320)							-- 6
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '������', 500)								-- 7
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '����������', 1000)						-- 8
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '�������', 1200)							-- 9
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '���', 2500)								-- 10
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '������', 1000)							-- 11
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������', '������', 1000)							-- 12
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��-�����', '�����', 1000)							-- 13
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '�����', 1500)							-- 14
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '�����', 1500)								-- 15
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '�������', 2000)							-- 16
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�����', '������', 1000)								-- 17
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������', '���', 2000)								-- 18
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������', '���', 2000)								-- 19
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '�����', 1500)								-- 20
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '��������', 500)							-- 21
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������-������', '���', 2000)						-- 22
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�����', '����', 1000)								-- 23
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '��������������', 2000)					-- 24
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�� ���', '���', 2000)								-- 25
INSERT INTO Cities(city_name, country_name, cost) VALUES ('����������', '������', 2000)							-- 26
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '�����', 1000)								-- 27
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��-������', '����', 2500)							-- 28
INSERT INTO Cities(city_name, country_name, cost) VALUES ('Sanshui', '�����', 1500)								-- 29
INSERT INTO Cities(city_name, country_name, cost) VALUES ('����������', '�����', 1000)							-- 30
INSERT INTO Cities(city_name, country_name, cost) VALUES ('Nyaung Lay Pin', '������ (�����)', 2500)				-- 31
INSERT INTO Cities(city_name, country_name, cost) VALUES ('���������', '�����', 2000)							-- 32
INSERT INTO Cities(city_name, country_name, cost) VALUES ('����������', '��������', 2000)						-- 33
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '�����', 1000)							-- 34
INSERT INTO Cities(city_name, country_name, cost) VALUES ('Dongbu-myeon', '����� �����', 1500)					-- 35
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������', '��������', 600)							-- 36
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������', '�������', 2500)							-- 37
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�������', '������', 400)							-- 38
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�����-�����', '������ ��������', 1000)				-- 39
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '��������������� ���������� �����', 1500)   -- 40
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '���', 2000)								-- 41
INSERT INTO Cities(city_name, country_name, cost) VALUES ('Sampang', '���������', 1500)							-- 42
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�����', '����', 2500)								-- 43
INSERT INTO Cities(city_name, country_name, cost) VALUES ('Bab Ezzouar', '�����', 1500)							-- 44
INSERT INTO Cities(city_name, country_name, cost) VALUES ('������', '��������', 800)							-- 45
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '�����', 1500)							-- 46
INSERT INTO Cities(city_name, country_name, cost) VALUES ('���������', '��������������', 1500)					-- 47
INSERT INTO Cities(city_name, country_name, cost) VALUES ('����������', '�����', 1500)							-- 48
INSERT INTO Cities(city_name, country_name, cost) VALUES ('Burdur', '������', 600)								-- 49
INSERT INTO Cities(city_name, country_name, cost) VALUES ('Changwon', '����� �����', 1500)						-- 50
INSERT INTO Cities(city_name, country_name, cost) VALUES ('�����������', '���������', 2600)						-- 51
INSERT INTO Cities(city_name, country_name, cost) VALUES ('��������', '������', 1600)							-- 52

INSERT INTO Planes(title, capacity, baggage_capacity) VALUES ('Boeing 737', 130, 23000)     -- 1
INSERT INTO Planes(title, capacity, baggage_capacity) VALUES ('Boeing 747', 800, 112630)    -- 2
INSERT INTO Planes(title, capacity, baggage_capacity) VALUES ('Airbus A380', 1378, 145400)  -- 3
INSERT INTO Planes(title, capacity, baggage_capacity) VALUES ('Airbus A230', 125, 23000)    -- 4
INSERT INTO Planes(title, capacity, baggage_capacity) VALUES ('Airbus A340', 279, 33550)    -- 5
INSERT INTO Planes(title, capacity, baggage_capacity) VALUES ('Airbus A320', 356, 40330)    -- 6
INSERT INTO Planes(title, capacity, baggage_capacity) VALUES ('Airbus A350', 475, 43550)    -- 7

INSERT INTO AirportPlanes(plane_id, planes_count) VALUES (1, 20)
INSERT INTO AirportPlanes(plane_id, planes_count) VALUES (3, 2)
INSERT INTO AirportPlanes(plane_id, planes_count) VALUES (4, 10)
INSERT INTO AirportPlanes(plane_id, planes_count) VALUES (7, 15)
INSERT INTO AirportPlanes(plane_id, planes_count) VALUES (5, 13)

INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 13)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 13)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 13)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 13)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 13)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 13)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 13)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 12)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (2, 1200)


INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (12, 10)

INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)
INSERT INTO Passagers(arrival_city, baggage_weight) VALUES (22, 10)

INSERT INTO DistributedPassagersGroups(arrival_city, baggage_weight, passagers_count) VALUES (22, 130000, 1345)
INSERT INTO DistributedPassagersGroups(arrival_city, baggage_weight, passagers_count) VALUES (12, 100000, 780) -- 2
INSERT INTO DistributedPassagersGroups(arrival_city, baggage_weight, passagers_count) VALUES (2, 125, 600) -- 1

INSERT INTO Flights(plane_id, distributed_group_id, arrival_city) VALUES (3, 1, 22)
INSERT INTO Flights(plane_id, distributed_group_id, arrival_city) VALUES (2, 2, 12)
INSERT INTO Flights(plane_id, distributed_group_id, arrival_city) VALUES (1, 3, 2)

GO