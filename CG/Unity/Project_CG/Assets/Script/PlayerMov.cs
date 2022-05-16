using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMov : MonoBehaviour
{

    private CharacterController controller;
    public float speed = 0.3f;
    private float boostsp = 1;
    public float rotSpeed;
    private float rot;
    public float gravity;
    private Vector3 moveDirection;
    private Animator anim;
    // Start is called before the first frame update
    void Start()
    {
        controller = GetComponent<CharacterController>();
        anim = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        Move();
    }
    void Move(){
        if (controller.isGrounded){
            if(Input.GetKey(KeyCode.W)){
                moveDirection = Vector3.forward *boostsp * speed;
                 anim.SetBool("IsWalking", true);
            }
        
            if(Input.GetKeyUp(KeyCode.W)){
                moveDirection = Vector3.zero;
                 anim.SetBool("IsWalking", false);
            }
            if(Input.GetKey(KeyCode.S)){
                moveDirection = Vector3.back * boostsp * speed;
                 anim.SetBool("IsWalking", true);
            }
            if(Input.GetKeyUp(KeyCode.S)){
                moveDirection = Vector3.zero;
                 anim.SetBool("IsWalking", false);
         }
            if(Input.GetKey(KeyCode.LeftShift)){
               boostsp = 2f;
            }
            if(Input.GetKeyUp(KeyCode.LeftShift)){
                boostsp = 1f;
            }
        }
         rot += Input.GetAxis("Horizontal") * rotSpeed * Time.deltaTime ;
         transform.eulerAngles = new Vector3(0,rot,0);

        moveDirection.y -= gravity * Time.deltaTime;
        moveDirection = transform.TransformDirection(moveDirection);
         controller.Move(moveDirection);
    }
   
}
