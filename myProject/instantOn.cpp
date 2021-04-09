#include <iostream>
#include <string>
using std::string;

typedef enum{
    DP_INITIALIZED = 0,
    DP_BOOTCOMPLETE,
    DP_SUSPEND,
    DP_CHECK_DP,
}DPState;

class CDirectPlay{
public:
    static bool BlockActiveSource( unsigned char saddr, const string& paddr );
    static void SetPowerStatus( bool b );
    static void SetFirstAppLaunch( bool b );
private:
    static void UpdateState();
    static void ClearAddr();
    static bool isValidAddr();
    static void DoActiveSource();

    static bool m_powerStatus;
    static bool m_firstAppLaunch;
    static DPState m_state;
    static unsigned char m_saddr;
    static string m_paddr;
};

bool CDirectPlay::m_powerStatus = false;
bool CDirectPlay::m_firstAppLaunch = false;
DPState CDirectPlay::m_state = DP_INITIALIZED;
unsigned char CDirectPlay::m_saddr = 0;
string CDirectPlay::m_paddr = "";

bool CDirectPlay::BlockActiveSource( unsigned char saddr, const string& paddr )
{
    if( m_state == DP_SUSPEND ){
        m_saddr = saddr;
        m_paddr = paddr;
        return true;
    }

    return false;
}

void CDirectPlay::SetPowerStatus( bool b )
{
    m_powerStatus = b;
    UpdateState();
}

void CDirectPlay::SetFirstAppLaunch( bool b )
{
    m_firstAppLaunch = b;
    UpdateState();
}

void CDirectPlay::ClearAddr()
{
    m_saddr = 0;
    m_paddr = "";
}

bool CDirectPlay::isValidAddr()
{
    if( m_saddr == 0 ) 
        return false;
        
    if( m_paddr.empty() )
        return false;

    if( m_paddr[0] < 1 || m_paddr[0] > 4 )
        return false;

    return true;
}
void CDirectPlay::DoActiveSource()
{
    printf("Do ActiveSource (%02X:%02X:%02X)\n", m_saddr << 4 | 0x0F, m_paddr[0], m_paddr[1]);
}

void CDirectPlay::UpdateState()
{
    bool needToCheckDirectPlay = false;
    DPState preState = m_state;

    switch( m_state ){
        case DP_INITIALIZED:
            if( m_powerStatus && m_firstAppLaunch )
               m_state = DP_BOOTCOMPLETE;  
            break;
        case DP_BOOTCOMPLETE:
            if( m_powerStatus == false ){
                m_state = DP_SUSPEND;
                ClearAddr();
            }
            break;
        case DP_SUSPEND:
            if( m_powerStatus && m_firstAppLaunch )
                needToCheckDirectPlay = true;
            break;
        default:
            break;
    }

    if( preState != m_state || needToCheckDirectPlay ){
        printf("m_state: %d -> %d, needToCheckDirectPlay: %d \n", preState, m_state, needToCheckDirectPlay);
    }

    if( needToCheckDirectPlay ){
        if( isValidAddr() ){
            DoActiveSource();
            m_state = DP_BOOTCOMPLETE;
            ClearAddr();
        }
    }

}

int main()
{
    // test1
    CDirectPlay::SetPowerStatus( true );
    CDirectPlay::SetFirstAppLaunch( true );
    CDirectPlay::SetPowerStatus( false );
    CDirectPlay::SetFirstAppLaunch( false );

    CDirectPlay::BlockActiveSource( 4, {0x01, 0x00} );

    CDirectPlay::SetPowerStatus( true );
    CDirectPlay::SetFirstAppLaunch( true );

    // test2
    CDirectPlay::SetPowerStatus( false );
    CDirectPlay::SetFirstAppLaunch( false );

    CDirectPlay::BlockActiveSource( 4, {0x01, 0x00} );

    CDirectPlay::SetFirstAppLaunch( true );
    CDirectPlay::SetPowerStatus( true );

    return 0;
}
