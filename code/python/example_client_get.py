import requests
import json


def get_data_from_server():
    url = "http://127.0.0.1:5001/tampil-data"

    try:
        response = requests.get(url, timeout=3)

        if response.status_code == 200:
            content_type = response.headers.get("Content-Type", "")
            print("Data berhasil diterima dari server:")

            if "application/json" in content_type:
                print(json.dumps(response.json(), indent=4))
            elif "text/plain" in content_type:
                print(response.text)
            else:
                print(response.text)
        else:
            print(f"Gagal menerima data. Status code: {response.status_code}")
    except Exception as e:
        print("Error menerima data:", e)


if __name__ == "__main__":

    get_data_from_server()
