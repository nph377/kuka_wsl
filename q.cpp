// is there any difference between this

RobotPrimitive::RobotPrimitive( const int ID, const char* Name )
{
	this->ID   = ID;
	this->Name = Name;
}

void RobotPrimitive::init( )
{

	// Initialize the Jacobian Matrices for the Robot
	this->JS = Eigen::MatrixXd::Zero( 6,  this->nq );
	this->JH = Eigen::MatrixXd::Zero( 6,  this->nq );
	this->JB = Eigen::MatrixXd::Zero( 6,  this->nq );

	// Initialize the Joint Twists and A Matrices
	this->JointTwists = Eigen::MatrixXd::Zero( 6,  this->nq );
	this->A_Mat1 	  = Eigen::MatrixXd::Zero( 6,  this->nq );
	this->A_Mat2 	  = Eigen::MatrixXd::Zero( 6 * this->nq,  this->nq );

	// Initialize the Mass Matrices
	this->M_Mat1 	  = Eigen::MatrixXd::Zero( 6 * this->nq,  6 * this->nq );
	this->M_Mat2 	  = Eigen::MatrixXd::Zero( 6 * this->nq,  6 * this->nq );

	// Initialize the L Matrix used for the Mass Matrix Computation
	this->L_Mat = Eigen::MatrixXd::Identity( 6 * this->nq, 6 * this->nq );

	// Once Initialization Complete, set the joint twists and generalized mass matrix
	this->setJointTwists( );
	this->setGeneralizedMassMatrix( );

}


// and this

class RobotPrimitive {
    public:

	const int ID;
	const char* Name;

    RobotPrimitive(const int ID, const char* Name) {
        this->ID = ID;
        this->Name = Name;

        // Initialize the Jacobian Matrices for the Robot
        this->JS = Eigen::MatrixXd::Zero( 6,  this->nq );
        this->JH = Eigen::MatrixXd::Zero( 6,  this->nq );
        this->JB = Eigen::MatrixXd::Zero( 6,  this->nq );

        // Initialize the Joint Twists and A Matrices
        this->JointTwists = Eigen::MatrixXd::Zero( 6,  this->nq );
        this->A_Mat1 	  = Eigen::MatrixXd::Zero( 6,  this->nq );
        this->A_Mat2 	  = Eigen::MatrixXd::Zero( 6 * this->nq,  this->nq );

        // Initialize the Mass Matrices
        this->M_Mat1 	  = Eigen::MatrixXd::Zero( 6 * this->nq,  6 * this->nq );
        this->M_Mat2 	  = Eigen::MatrixXd::Zero( 6 * this->nq,  6 * this->nq );

        // Initialize the L Matrix used for the Mass Matrix Computation
        this->L_Mat = Eigen::MatrixXd::Identity( 6 * this->nq, 6 * this->nq );

        // Once Initialization Complete, set the joint twists and generalized mass matrix
        this->setJointTwists( );
        this->setGeneralizedMassMatrix( );
    }
}
