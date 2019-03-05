#MAKE SURE PYTHONPATH IS SET!
from squealercpp.sql_database import Table, Connection, DataBase


def test_table():

    table = Table("example.db")
    assert table.table_name == "example.db"

def test_database():
    #pass
    db = DataBase("example.db")
    assert db.db_path == "example.db"

    
    assert len(db.tables) == 0
    # feat = {"ID": "INT"}
    feat = {"ID": "INT", "NAME": "TEXT"}
    # REMEMBER CREATE TABLE CAN ONLY CREATE ONCE FOR NOW
    # IMPLEMENT OVERWRITE FLAG
    db.create_table("COMPANY", feat)
    assert len(db.tables) == 1
    assert list(db.tables) == ["COMPANY"]
    assert db.tables["COMPANY"].table_name == "COMPANY"

    assert db.tables["COMPANY"].columns["ID"] == "INT"
    assert db.tables["COMPANY"].columns["NAME"] == "TEXT"


def connection():

    con = Connection("test.db")
    assert con.db_path == "test.db"
    #pass

if __name__ == "__main__":
    test_database()
