import requests


def send_data_to_server(data):
    url = "http://127.0.0.1:5001/data"

    try:
        response = requests.post(url, json=data, timeout=3)

        if response.status_code == 201:
            print("Data berhasil dikirim ke server.")
        else:
            print(f"Gagal mengirim data. Status code: {response.status_code}")
    except Exception as e:
        print("Error saat mengirim data:", e)


if __name__ == "__main__":
    # Contoh data yang akan dikirim
    data = {"device_id": "rangkaian-2", "jarak": 15, "buzzer": 1}

    send_data_to_server(data)
