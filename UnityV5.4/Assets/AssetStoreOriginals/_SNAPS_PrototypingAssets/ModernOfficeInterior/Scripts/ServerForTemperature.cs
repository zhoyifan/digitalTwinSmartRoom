using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using System.Net;
using UnityEngine;
using UnityEngine.UI;
using System.Net.Sockets;
using System.Text;
using UnityEngine.SceneManagement;

public class ServerForTemperature : MonoBehaviour
{
    [SerializeField]
    public TcpListener server;
    public Text temperaturefromServerText;
    public Text temperatureRoomText;

    //Default host and port
    string host = "127.0.0.1";
    int portTemperature = 52056;
    //private string displaymessage = "";
    float temperaturefromServer;
    float temperatureRoom;
    bool isTiming;
    Thread tcpListenerThread;
    private float hvacStatus;
    float timeDelay = 1;
    // Use this for initialization
    public void Start()
    {
        tcpListenerThread = new Thread(() => ListenForMessages());
        tcpListenerThread.Start();
        //displaymessage = "Not Connected!";

        hvacStatus = this.GetComponent<ServerForHVAC>().GetHvacstatus();
        temperatureRoom = 30;
        temperaturefromServer = 20;
        isTiming = false;
    }

    public void Update()
    {
        temperaturefromServerText.text="target temperature: "+temperaturefromServer.ToString();
        temperatureRoomText.text = "room temperature: " + temperatureRoom.ToString();
        if (isTiming == false)
        {
            if (Math.Abs(temperatureRoom - temperaturefromServer) > 0.1)
            {
                if (temperatureRoom - temperaturefromServer > 0)
                {
                    temperatureRoomText.color = Color.blue;
                    this.GetComponent<ServerForHVAC>().SetHvacstatus(2);
                    StartCoroutine(HvacChangeTemperature(2));
                }
                else
                {
                    temperatureRoomText.color = Color.red;
                    this.GetComponent<ServerForHVAC>().SetHvacstatus(1);
                    StartCoroutine(HvacChangeTemperature(1));
                }
            }
            else
            {
                temperatureRoom = temperaturefromServer;
                temperatureRoomText.color = Color.white;
                this.GetComponent<ServerForHVAC>().SetHvacstatus(0);
            }
        }
    }
    IEnumerator HvacChangeTemperature(float mode)
    {
        isTiming = true;
        yield return new WaitForSeconds(timeDelay);
        this.GetComponent<ServerForHVAC>().SetHvacstatus(mode);
        if (mode == 1)
        {
            temperatureRoom = temperatureRoom + 0.1f;
        }
        else {
            temperatureRoom = temperatureRoom - 0.1f;
        }
        
        isTiming = false;
    }
    public void ListenForMessages()
    {

        try
        {
            // Set the TcpListener on port 13000.
            IPAddress localAddr = IPAddress.Parse(host);

            // TcpListener server = new TcpListener(port);
            server = new TcpListener(localAddr, portTemperature);

            // Start listening for client requests.
            server.Start();

            // Buffer for reading data
            Byte[] bytes = new Byte[1024];      //The byte array containing the sequence of bytes to decode.
            String data = null;
            //int counter = 0;
            // Enter the listening loop.
            while (true)
            {
                // Perform a blocking call to accept requests.
                // You could also user server.AcceptSocket() here.
                using (TcpClient client = server.AcceptTcpClient())
                {
                    data = null;

                    // Get a stream object for reading and writing
                    NetworkStream stream = client.GetStream();

                    int i;      //The number of bytes to decode

                    // Loop to receive all the data sent by the client.
                    while ((i = stream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        // Translate data bytes to a ASCII string.
                        data = System.Text.Encoding.ASCII.GetString(bytes, 0, i);  // 0 is The index of the first byte to decode.
                        float temperaturefromRhapsody = (float)Convert.ToDouble(data);
                        //Debug.Log(data);
                        temperaturefromServer = temperaturefromRhapsody;
                        //Debug.Log("Temperature: " + temperaturefromServer);
                        // Process the data sent by the client.
                        data = data.ToUpper();

                        byte[] msg = System.Text.Encoding.ASCII.GetBytes(data);

                        // Send back a response.
                        stream.Write(msg, 0, msg.Length);
                    }
                    // Shutdown and end connection
                    client.Close();
                }


            }
        }
        catch (SocketException e)
        {
            Debug.LogError(String.Format("SocketException: {0}", e));
        }
        finally
        {
            // Stop listening for new clients.
            server.Stop();
        }
    }
}