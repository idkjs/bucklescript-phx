open Phx_abstract;
type t = {
  .
  /*constructor(channel: Channel, event: string, payload: any, timeout: number);*/
  /*defined as function in Phx_channel duo to circle dependency*/
  /*resend(timeout: number): void;*/
  [@bs.meth] "resend": float => void,
  /*send(): void;*/
  [@bs.get] "send": void,
  /*receive(status: string, callback: (response?: any) => void): Push;*/
  [@bs.meth] "receive": (string, any => void) => t,
};
