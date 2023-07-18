
-- QUERY 1 Create Tables
CREATE TABLE person
(
  driverid varchar(10),
  name varchar(20),
  address varchar(30),
  primary key(driverid)
);

CREATE TABLE car
(
  regno varchar(10),
  model varchar(10),
  year int,
  primary key(regno)
);

CREATE TABLE accident
(
  reportno int,
  date date,
  location varchar(20),
  primary key(reportno)
);

CREATE TABLE owns
(
  driverid varchar(10),
  regno varchar(10),
  primary key(driverid,regno),
  foreign key(driverid) references person(driverid),
  foreign key(regno) references car(regno)
);

CREATE TABLE participated(
  Driverid varchar(10),
  regno varchar(10),
  reportno int,
  damageamt int,
  primary key(driverid,regno,reportno),
  foreign key(driverid) references person(driverid),
  foreign key(regno) references car(regno),
  foreign key(reportno) references accident(reportno)
);

-- QUERY 2 Insert Values
INSERT INTO person VALUES ('D1', 'John Doe', '123 Main St');
INSERT INTO person VALUES ('D2', 'Jane Smith', '456 Elm St');
INSERT INTO person VALUES ('D3', 'Michael Johnson', '789 Oak St');

INSERT INTO car VALUES ('C1', 'Toyota', 2020);
INSERT INTO car VALUES ('C2', 'Honda', 2018);
INSERT INTO car VALUES ('C3', 'Ford', 2019);

INSERT INTO accident VALUES (1, '01-JAN-2023', 'Intersection A');
INSERT INTO accident VALUES (12, '05-JAN-2023', 'Highway B');
INSERT INTO accident VALUES (3, '10-JAN-2008', 'Street C');

INSERT INTO owns VALUES ('D1', 'C1');
INSERT INTO owns VALUES ('D2', 'C2');
INSERT INTO owns VALUES ('D3', 'C3');

INSERT INTO participated VALUES ('D1', 'C1', 1, 1000);
INSERT INTO participated VALUES ('D2', 'C2', 12, 2000);
INSERT INTO participated VALUES ('D3', 'C3', 3, 1500);

select * from person;
select * from participated;

-- QUERY 3 
UPDATE participated
set damageamt=25000
WHERE regno='C2' AND reportno=12;

-- QUERY 4
select count(distinct driverid) CNT
from participated a, accident b
where a.reportno=b.reportno and b.date like '%08';

-- QUERY 5
select count(reportno) CNT
from car c, participated p
where c.regno=p.regno and model='Honda';