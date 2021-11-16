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

public class ServerForHVAC : MonoBehaviour
{
    [SerializeField]
    public TcpListener server;

    public Text temperatureRoomText;
    public Text Co2densityText;
    //Default host and port
    string host = "127.0.0.1";
    int portHVACstatus = 10006;
    float hvacstatusfromServer;
    public ParticleSystem hvacsystem1;   //this shows the white smoke
    public ParticleSystem hvacsystem2;   //this too

    Thread tcpListenerThread;

    public float GetHvacstatus() { return hvacstatusfromServer; }
    public void SetHvacstatus(float newStatus) { hvacstatusfromServer = newStatus; }

    // Use this for initialization
    public void Start()
    {
        hvacstatusfromServer = 0;
        tcpListenerThread = new Thread(() => ListenForMessages());
        tcpListenerThread.Start();
        //displaymessage = "Not Connected!";
    }

    public void Update()
    {
        changehvacstatus();
        //Debug.Log("hvacstatusfromServer : " + hvacstatusfromServer.ToString());
    }

    public void ListenForMessages()
    {

        try
        {
            // Set the TcpListener on port 13000.
            IPAddress localAddr = IPAddress.Parse(host);

            // TcpListener server = new TcpListener(port);
            server = new TcpListener(localAddr, portHVACstatus);

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
                        float hvacstatusfromRhapsody = (float)Convert.ToDouble(data);
                        Debug.Log("data : "+data);
                        hvacstatusfromServer = Mathf.Round(hvacstatusfromRhapsody);
                        //Debug.Log("HVAC Status: " + hvacstatusfromServer);
                        // Process the data sent by the client.

                        String hvacToRhapsody = Mathf.Round(hvacstatusfromServer).ToString("0.00").ToUpper();
                        Debug.Log("hvacToRhapsody : " + hvacToRhapsody);
                        byte[] msg = System.Text.Encoding.ASCII.GetBytes(hvacToRhapsody);

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

    public void changehvacstatus()
    {
        if (hvacstatusfromServer == 0)
        {
            temperatureRoomText.color=Color.white;
            Co2densityText.color=Color.white;
            hvacsystem1.enableEmission = false;
            hvacsystem2.enableEmission = false;
            hvacsystem1.GetComponent<AudioSource>().enabled=false;
        }else{
            hvacsystem1.GetComponent<AudioSource>().enabled=true;
        }
        if (hvacstatusfromServer == 1)
        {
            temperatureRoomText.color=Color.red;
            hvacsystem1.enableEmission = true;
            hvacsystem1.GetComponent<ParticleSystem>().startColor = Color.red;
            hvacsystem2.enableEmission = true;
            hvacsystem2.GetComponent<ParticleSystem>().startColor = Color.red;
        }
        if (hvacstatusfromServer == 2)
        {
            temperatureRoomText.color=Color.blue;
            hvacsystem1.enableEmission = true;
            hvacsystem1.GetComponent<ParticleSystem>().startColor = Color.blue;
            hvacsystem2.enableEmission = true;
            hvacsystem2.GetComponent<ParticleSystem>().startColor = Color.blue;
        }
        if (hvacstatusfromServer == 3)
        {
            Co2densityText.color=Color.green;
            hvacsystem1.enableEmission = true;
            hvacsystem1.GetComponent<ParticleSystem>().startColor = Color.white;
            hvacsystem2.enableEmission = true;
            hvacsystem2.GetComponent<ParticleSystem>().startColor = Color.white;
        }

    }
}