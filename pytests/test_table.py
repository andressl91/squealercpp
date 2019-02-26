#MAKE SURE PYTHONPATH IS SET!
from squealercpp.sql_database import Table


def test_table():

    table = Table("example.db")
    assert table.table_name == "example.db"

