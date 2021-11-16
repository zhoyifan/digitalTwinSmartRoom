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

public class ServerForLights : MonoBehaviour
{
    [SerializeField]
    public TcpListener server;
    public Light light1;
    public Light light2;
    public Light light3;
    public Light light4;
    public Light light5;
    // Range Variables
    //public bool changeRange = false;
    //public float rangeSpeed = 1.0f;
    //public float maxRange = 10.0f;
    //public bool repeatRange = false;

    // Intensity Variables
    //private bool changeIntensity = true;
    //private float intensitySpeed = 1.0f;
    //private float maxIntensity = 1.0f;
    //public bool repeatIntensity = false;
    //Default host and port
    string host = "127.0.0.1";
    int portLight = 40000;
    //private string displaymessage = "";
    float intensityfromServer;

    Thread tcpListenerThread;

    // Use this for initialization
    public void Start()
    {
        intensityfromServer = 10;
        tcpListenerThread = new Thread(() => ListenForMessages());
        tcpListenerThread.Start();
        //displaymessage = "Not Connected!";
    }

    public void Update()
    {

        //if (changeIntensity)
        //{
            changeLightIntensity();
        //}
        
    }

    public void ListenForMessages()
    {

        try
        {
            // Set the TcpListener on port 13000.
            IPAddress localAddr = IPAddress.Parse(host);

            // TcpListener server = new TcpListener(port);
            server = new TcpListener(localAddr, portLight);

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
                        float intensityfromRhapsody = (float)Convert.ToDouble(data);

                        intensityfromServer = intensityfromRhapsody;

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

    public void changeLightIntensity()
    {
        //if (repeatIntensity)
        //{
        //    light1.intensity = Mathf.PingPong(Time.time * intensityfromServer, maxIntensity);
        //    light2.intensity = Mathf.PingPong(Time.time * intensityfromServer, maxIntensity);
        //    light3.intensity = Mathf.PingPong(Time.time * intensityfromServer, maxIntensity);
        //    light4.intensity = Mathf.PingPong(Time.time * intensityfromServer, maxIntensity);
        //    light5.intensity = Mathf.PingPong(Time.time * intensityfromServer, maxIntensity);
        //}
        //else
        //{
            //light1.intensity = Time.time * intensityfromServer;
            //light2.intensity = Time.time * intensityfromServer;
            //light3.intensity = Time.time * intensityfromServer;
            //light4.intensity = Time.time * intensityfromServer;
            //light5.intensity = Time.time * intensityfromServer;
            light1.intensity = intensityfromServer;
            light2.intensity = intensityfromServer;
            light3.intensity = intensityfromServer;
            light4.intensity = intensityfromServer;
            light5.intensity = intensityfromServer;
            //if (light1.intensity >= maxIntensity)
            //{
            //    changeIntensity = false;
            //}
            //if (light2.intensity >= maxIntensity)
            //{
            //    changeIntensity = false;
            //}
            //if (light3.intensity >= maxIntensity)
            //{
            //    changeIntensity = false;
            //}
            //if (light4.intensity >= maxIntensity)
            //{
            //    changeIntensity = false;
            //}
            //if (light5.intensity >= maxIntensity)
            //{
            //    changeIntensity = false;
            //}
            //Debug.Log("Max Intensity: "+maxIntensity);
            //Debug.Log("Intensity: " + light1.intensity);
        //}
        
    }
}