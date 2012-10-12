import json;
from pprint import pprint;

json_string = """{"skillz": {
	"web":[
		{"name": "html", 
		 "years": "5"
		},
		{"name": "css", 
		 "years": "3"
		}],
	"database":[
		{"name": "sql", 
		 "years": "7"
		}]
}}
"""

#pprint(dir(json));
decode_string = json.loads(json_string)
#print type(json.dumps(decode_string));
print decode_string;#["skillz"]["web"][0]["name"];