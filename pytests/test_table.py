#MAKE SURE PYTHONPATH IS SET!
from squealercpp.sql_database import Table, Connection, DataBase


def test_table():

    table = Table("example.db")
    assert table.table_name == "example.db"

def test_database():
    #pass
    db_name = "example.db"
    with open(db_name, "w"):
        pass
    db = DataBase("example.db")
    assert db.db_path == "example.db"

    # Test creating of new table
    assert len(db.tables) == 0
    feat = {"ID": "INT", "NAME": "TEXT"}
    db.create_table("COMPANY", feat)
    assert len(db.tables) == 1
    assert list(db.tables) == ["COMPANY"]

    # Check table attributes after creation
    assert db.tables["COMPANY"].table_name == "COMPANY"
    assert db.tables["COMPANY"].columns["ID"] == "INT"
    assert db.tables["COMPANY"].columns["NAME"] == "TEXT"

    # CHECK AT WE SUPPORT ALL BASIC TYPES (NOT BLOB YET)
    feat = {"JIB": "TEXT", "JAB": "INT", "JOB": "REAL"}
    # Make sure we do not create new table woth flag
    db.create_table("COMPANY", feat, overwrite=False)
    assert db.tables["COMPANY"].columns["ID"] == "INT"
    assert db.tables["COMPANY"].columns["NAME"] == "TEXT"

    # Check flag deletes table, (NOT CLEANSE)
    db.create_table("COMPANY", feat, overwrite=True)
    assert db.tables["COMPANY"].columns["JIB"] == "TEXT"
    assert db.tables["COMPANY"].columns["JAB"] == "INT"
    assert db.tables["COMPANY"].columns["JOB"] == "REAL"

    table = db.tables["COMPANY"]
    
    insert_data = [{"JIB": "JUDAS", "JAB": 2, "JOB": 4.41},
                   {"JIB": "PRIEST", "JAB": 4, "JOB": 8.81}]

    #table.insert(insert_data)
    
    # WORKS
    # table.bulk_insert(insert_data)
    
    # WIP
    table.bulk_insert_v2(insert_data)
    
    # WORKS WITH ONLY ONE
    #table.bulk_insert_v2([insert_data[0]])


def test_delete():

    db_name = "example.db"
    with open(db_name, "w"):
        pass
    db = DataBase("example.db")
    assert db.db_path == "example.db"

    feat = {"ID": "TEXT", "NAME": "TEXT"}
    db.create_table("COMPANY", feat)
    table = db.tables["COMPANY"]
    
    insert_stmt = {"ID": "TE", "NAME": "ANDY"}
    # insert_stmt = {"ID": "ME", "NAME": "ANDY"}
    table.insert(insert_stmt)

def connection():

    con = Connection("test.db")
    assert con.db_path == "test.db"
    #pass

if __name__ == "__main__":
    test_database()
