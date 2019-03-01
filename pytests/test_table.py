#MAKE SURE PYTHONPATH IS SET!
from squealercpp.sql_database import Table, Connection


def test_table():

    table = Table("example.db")
    assert table.table_name == "example.db"

def test_database():
    #db = DataBase("example.db")
    #assert db.db_path == "example.db"

def connection():
    pass
